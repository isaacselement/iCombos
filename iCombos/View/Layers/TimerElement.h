#ifndef __iCombos__TimerElement__
#define __iCombos__TimerElement__

#include "Interval.h"


class CountdownTimer;


class TimerElement: public Layer
{
private:
    
    
public:
    virtual bool init();
    CREATE_FUNC(TimerElement);
    
    Label* timeLabel;
    CountdownTimer* timer;
};

#endif /* defined(__iCombos__TimerElement__) */
