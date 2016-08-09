#include "EventManager.h"
#include "Classes.h"

bool EventManager::isGameStarted = false;

#pragma mark - 

static EventManager* s_sharedEventManager = nullptr;
EventManager* EventManager::getInstance()
{
    if (!s_sharedEventManager) {
        s_sharedEventManager = new (std::nothrow) EventManager();
        CCASSERT(s_sharedEventManager, "Fatal: no enough memory");
        s_sharedEventManager->init();
    }
    return s_sharedEventManager;
}

bool EventManager::init()
{
    return true;
}


#pragma mark - Touch Event

bool EventManager::onTouchBegan(Touch *touch, Event *unused_event)
{
    return true;
}

void EventManager::onTouchMoved(Touch *touch, Event *unused_event)
{
}

void EventManager::onTouchEnded(Touch *touch, Event *unused_event)
{
    if (!EventManager::isGameStarted) {
        isGameStarted = true;
        EffectManager::explodeEffect();
        EventManager::startGame();
    } else {
        EventManager::shootEvent(touch->getLocation());
    }
}


#pragma mark - 

void EventManager::launchGame()
{
    StatisticsPanel* panel = LayerManager::getStatisticsPanel();
    getStatisticsValueToPanel(panel->shieldCountElement, kState_shieldsCount);
    getStatisticsValueToPanel(panel->spearCountElement, kState_spearsCount);
    getStatisticsValueToPanel(panel->damageCountElement, kState_damagesCount);
    getStatisticsValueToPanel(panel->totalHitsCountElement, kState_totalHitsCount);
    
    StateManager::getInstance()->currentWaveSum = 0;
}

void EventManager::startGame()
{
    StatisticsPanel* staticPanel = LayerManager::getStatisticsPanel();
    
    int destroyHits = RANDOM(1, 3);
    StateManager::getInstance()->destroyHits = destroyHits;
    staticPanel->setCountToValuelabel(staticPanel->hitPerDamageElement, destroyHits);
    
    
    staticPanel->setTimer(RANDOM(5, 10));
    staticPanel->startTimer();
    
    // The fall interval
    float interval = 1.0f;
    if (destroyHits == 3) {
        interval = 1.0 + CCRANDOM_0_1() * 2;
    }
    ViewScheduler::getInstance()->startShieldsFallDown(1.0f);
    
    
    // About change color animation
    Color3B startColor = ViewManager::getRandomColor();
    Color3B endColor = ViewManager::getRandomColor();
    if (random(1, 5) == 3) {
        if (random(1, 5) == 2) startColor = Color3B(0, 0, 0);
        endColor = startColor;
    }
    MainLayer* mainLayer = LayerManager::getMainLayer();
    Color3B oldStartColor = mainLayer->getStartColor();
    Color3B oldEndColor = mainLayer->getEndColor();
    if (StateManager::getInstance()->currentWaveSum == 0) {
        mainLayer->setStartColor(startColor);
        mainLayer->setEndColor(endColor);
        
        mainLayer->effectLayer->runAction(FadeOut::create(1));
        
    } else {
        if (StateManager::getInstance()->currentWaveSum % 2 == 0) {
            mainLayer->effectLayer->setStartColor(startColor);
            mainLayer->effectLayer->setEndColor(endColor);
            mainLayer->effectLayer->runAction(FadeOut::create(0));
            mainLayer->effectLayer->runAction(FadeIn::create(1));
        } else {
            mainLayer->setStartColor(startColor);
            mainLayer->setEndColor(endColor);
            
            mainLayer->effectLayer->setStartColor(oldStartColor);
            mainLayer->effectLayer->setEndColor(oldEndColor);
            mainLayer->effectLayer->runAction(FadeIn::create(0));
            mainLayer->effectLayer->runAction(FadeOut::create(1));
        }
    }
    
    StateManager::getInstance()->currentWaveSum++;
}

void EventManager::pauseGame()
{
    ViewScheduler::getInstance()->stopShieldsFallDown();
    Director::getInstance()->pause();
}

void EventManager::finishGame()
{
    ViewScheduler::getInstance()->stopShieldsFallDown();
    
    Label* waveLabel = Label::create();
    waveLabel->setSystemFontSize(CanvasFontSize(80));
    waveLabel->setPosition(VecHelper::getWindowCenter());
    LayerManager::getMainLayer()->addChild(waveLabel);
    
    int waveCount = setStatisticsValue(kState_waveCount);
    
    std::string string = StringHelper::intToString(waveCount);
    string = std::string("Wave ").append(string).append(" is comming");
    waveLabel->setString(string);

    CountdownTimer* timer = CountdownTimer::createTimer();
    timer->setTime(random(0.5, 2.5));
    timer->setVisible(false);
    timer->setPosition(VecHelper::getWindowCenter());
    timer->timesOverCallback = [=]{
        timer->removeFromParent();
        waveLabel->removeFromParent();
        
        EventManager::startGame();
    };
    timer->start();
    LayerManager::getMainLayer()->addChild(timer);
}

void EventManager::timesOverEvent()
{
    finishGame();
}



void EventManager::fallEvent()
{
    Size winSize = Director::getInstance()->getWinSize();
    float width = winSize.width;
    int w = rand() % (int)width;
    
    auto shield = Shield::create();
    
    // Fall
    int multi = 1;
    float duration = RANDOM(2, 5);
    int destroyHits = StateManager::getInstance()->destroyHits;
    if (destroyHits == 2) {
        duration = RANDOM(3, 6);
        multi = RANDOM(1, 3);
    } else if (destroyHits == 3) {
        duration = RANDOM(4, 10);
        multi = RANDOM(2, 4);
    }
    shield->setHeaderSizeMultiple(multi);

    Vec2 destination = Vec2(w, -winSize.height - CanvasH(1600));
    Vec2 position = Vec2(w, winSize.height);
    shield->run(duration, position, destination);
    
    LayerManager::getMainLayer()->addChild(shield);
    
    setStatisticsValueToPanel(LayerManager::getStatisticsPanel()->shieldCountElement, kState_shieldsCount);
}

void EventManager::shootEvent(Vec2 location )
{
    Size winSize = Director::getInstance()->getWinSize();
    MainLayer* mainLayer = LayerManager::getMainLayer();
    
    auto spear = Spear::create();
    
    // Shoot
    float duration = 5.0f;
    Vec2 destination = Vec2(location.x, winSize.height + CanvasH(1150));
    spear->run(duration, location, destination);
    
    mainLayer->addChild(spear);
    
    AudionManager::getInstance()->playShootAudio();
    
    setStatisticsValueToPanel(LayerManager::getStatisticsPanel()->spearCountElement, kState_spearsCount);
}

void EventManager::hitEvent(Spear *spear, Shield *shield, cocos2d::Vec2 location)
{
    EffectManager::hitEffect(location, shield->getHeaderSizeMultiple());
    
    // remove , release
    spear->removeRoleSelf(0);
    
    shield->hitCount++;
    if (shield->hitCount == StateManager::getInstance()->destroyHits) {
        shield->removeRoleSelf(0);
        
        setStatisticsValueToPanel(LayerManager::getStatisticsPanel()->damageCountElement, kState_damagesCount);
    }
    setHitRateValueToPanel();
}





void EventManager::setHitRateValueToPanel()
{
    setStatisticsValue(kState_totalHitsCount);
    getHitRateValueToPanel();
}

void EventManager::getHitRateValueToPanel()
{
    float rate = (float)getStatisticsValue(kState_totalHitsCount) / (float)getStatisticsValue(kState_spearsCount);
    std::string rateStr = StringHelper::floatToString(rate);
    LayerManager::getStatisticsPanel()->totalHitsCountElement->valueLabel->setString(rateStr);
}


void EventManager::setStatisticsValueToPanel(StatisticsElement *ele, const char* stateKey)
{
    setStatisticsValue(stateKey);
    getStatisticsValueToPanel(ele, stateKey);
}

void EventManager::getStatisticsValueToPanel(StatisticsElement *ele, const char *stateKey)
{
    LayerManager::getStatisticsPanel()->setCountToValuelabel(ele, getStatisticsValue(stateKey));
}

int EventManager::setStatisticsValue(const char *stateKey)
{
    int count = getStatisticsValue(stateKey);
    count++;
    UserDefault::getInstance()->setIntegerForKey(stateKey, count);
    return count;
}

int EventManager::getStatisticsValue(const char *stateKey)
{
    int count = UserDefault::getInstance()->getIntegerForKey(stateKey);
    return count;
}
