#include "TimerElement.h"
#include "Classes.h"

bool TimerElement::init()
{
    
    timeLabel = Label::create();
    this->addChild(timeLabel);
    
    
    timer = CountdownTimer::createTimer();
    this->addChild(timer);
    
    return true;
}
