#include "ViewScheduler.h"
#include "Classes.h"


static ViewScheduler* instance ;
ViewScheduler* ViewScheduler::getInstance()
{
    if (instance == nullptr) {
        instance = new ViewScheduler();
    }
    return instance;
}

void ViewScheduler::startShieldsFallDown(float interval)
{
    Director::getInstance()->getScheduler()->schedule(schedule_selector(ViewScheduler::scheduleShield), this, interval, kRepeatForever, 0, false);
}

void ViewScheduler::stopShieldsFallDown()
{
    Director::getInstance()->getScheduler()->unschedule(schedule_selector(ViewScheduler::scheduleShield), this);
}

void ViewScheduler::scheduleShield(float dt)
{
    EventManager::getInstance()->fallEvent();
}
