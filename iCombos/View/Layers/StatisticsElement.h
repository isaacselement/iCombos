#ifndef __iCombos__StatisticsElement__
#define __iCombos__StatisticsElement__

#include "Interval.h"

class StatisticsElement: public Layer
{
private:
    
    
public:
    
    virtual bool init();
    CREATE_FUNC(StatisticsElement);
    
    Label* keyLabel;
    Label* valueLabel;
    
};

#endif /* defined(__iCombos__StatisticsElement__) */
