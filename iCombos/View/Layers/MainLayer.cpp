#include "MainLayer.h"
#include "Classes.h"

bool MainLayer::init()
{
    if (!LayerGradient::init()) {
        return false;
    }
    
    effectLayer = LayerGradient::create();
    effectLayer->setContentSize(Director::getInstance()->getWinSize());
    addChild(effectLayer);
    
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [](PhysicsContact& contact) {
        Role* a = dynamic_cast<Role * >(contact.getShapeA()->getBody()->getNode());
        Role* b = dynamic_cast<Role * >(contact.getShapeB()->getBody()->getNode());
        if(a && b) {
            Spear* spear = (Spear*)a;
            Shield* shield = (Shield*)b;
            if (a->getClassTypeName() == clazz_Shield) {
                shield = (Shield*)a;
                spear = (Spear*)b;
            }
            const PhysicsContactData* contactData = contact.getContactData();
            EventManager::getInstance()->hitEvent(spear, shield, contactData->points[0]);
        }
        return true;
    };
    
    listener->onContactPreSolve = [](PhysicsContact& contact, PhysicsContactPreSolve& solve) {
        return true;
    };
    
    listener->onContactPostSolve = [](PhysicsContact& contact, const PhysicsContactPostSolve& solve) {
    };
    
    listener->onContactSeparate = [](PhysicsContact& contact) {
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(EventManager::onTouchBegan, EventManager::getInstance());
    touchListener->onTouchMoved = CC_CALLBACK_2(EventManager::onTouchMoved, EventManager::getInstance());
    touchListener->onTouchEnded = CC_CALLBACK_2(EventManager::onTouchEnded, EventManager::getInstance());
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

