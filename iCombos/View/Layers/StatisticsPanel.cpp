#include "StatisticsPanel.h"
#include "Classes.h"

bool StatisticsPanel::init()
{
    rapidjson::Value& statisticsPanelObj = DataManager::getInstance()->configs["StatisticsPanel"];
    rapidjson::Value& startColorVal = statisticsPanelObj["startColor"];
    rapidjson::Value& endColorVal = statisticsPanelObj["endColor"];
    
    Color4B startColor = rParseColor4B(startColorVal);
    Color4B endColor = rParseColor4B(endColorVal);
    if (!LayerGradient::initWithColor(startColor, endColor)) {
        return false;
    }
    
    int height = CanvasH(rParseInt(statisticsPanelObj["height"]));
    this->setContentSize(Size(SizeHelper::getWinSizeWidth(), height));
    this->setPosition(0, SizeHelper::getWinSizeHeight() - this->getContentSize().height);
    
    
    /////////---------------------- Timer Begin ---------------------
    timerElement = TimerElement::create();
    this->addChild(timerElement);
    CountdownTimer* timer = timerElement->timer;
    Label* timerLabel = timer->label;
    Label* label = timerElement->timeLabel;
    
    rapidjson::Value& timerElementObj = statisticsPanelObj["TimerElement"];
    rapidjson::Value& timerObj = timerElementObj["Timer"];
    rapidjson::Value& timerLabelObj = timerObj["Label"];
    rapidjson::Value& labelObj = timerElementObj["Label"];
    
    timer->timesOverCallback = [](){ EventManager::getInstance()->timesOverEvent(); };
    
    RapidjsonNoder::applyNodeProperties(timerElement, timerElementObj);
    RapidjsonNoder::applyNodeProperties(timer, timerObj);
    RapidjsonNoder::applyLabelProperties(timerLabel, timerLabelObj);
    RapidjsonNoder::applyLabelProperties(label, labelObj);
    /////////---------------------- Timer End ---------------------
    
    
    // statistics labels
    spearCountElement = createStatisticsElement(statisticsPanelObj["spearCountElement"]);
    shieldCountElement = createStatisticsElement(statisticsPanelObj["shieldCountElement"]);
    damageCountElement = createStatisticsElement(statisticsPanelObj["damageCountElement"]);
    hitPerDamageElement = createStatisticsElement(statisticsPanelObj["hitPerDamageElement"]);
    totalHitsCountElement = createStatisticsElement(statisticsPanelObj["totalHitsCountElement"]);
    
    return true;
}

StatisticsElement* StatisticsPanel::createStatisticsElement(rapidjson::Value &config)
{
    StatisticsElement* element = StatisticsElement::create();
    this->addChild(element);
    
    if (!config.IsNull()) {
        RapidjsonNoder::applyNodeProperties(element, config);
        RapidjsonNoder::applyLabelProperties(element->keyLabel, config["KeyLabel"]);
        RapidjsonNoder::applyLabelProperties(element->valueLabel, config["ValueLabel"]);        
    }
    
    return element;
}

void StatisticsPanel::setTimer(float time)
{
    timerElement->timer->setTime(time);
    timerElement->timer->label->setString("-- : -- : --");
}

void StatisticsPanel::startTimer()
{
    timerElement->timer->start();
}

void StatisticsPanel::setCountToValuelabel(StatisticsElement* element, int count)
{
    element->valueLabel->setString(StringHelper::intToString(count));
}
