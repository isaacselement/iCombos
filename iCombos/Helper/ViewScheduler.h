#ifndef __iCombos__ViewScheduler__
#define __iCombos__ViewScheduler__

#include "Interval.h"

class ViewScheduler: public Ref
{
private: 
    
    
public:
    static ViewScheduler* getInstance();
    
    void startShieldsFallDown(float interval);
    void stopShieldsFallDown();
    void scheduleShield(float dt);
};

#endif /* defined(__iCombos__ViewScheduler__) */
