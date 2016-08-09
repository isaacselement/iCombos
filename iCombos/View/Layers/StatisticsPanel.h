#ifndef __iCombos__StatisticsPanel__
#define __iCombos__StatisticsPanel__

#include "Interval.h"

class StatisticsElement;
class TimerElement;

class StatisticsPanel: public LayerGradient
{
private:
    TimerElement* timerElement;
    
    
    StatisticsElement* createStatisticsElement(rapidjson::Value& config);
    
public:
    
    virtual bool init();
    CREATE_FUNC(StatisticsPanel);
    
    void setTimer(float time);
    void startTimer();
    
    StatisticsElement* spearCountElement;
    StatisticsElement* shieldCountElement;
    StatisticsElement* damageCountElement;
    StatisticsElement* hitPerDamageElement;
    StatisticsElement* totalHitsCountElement;
    
    void setCountToValuelabel(StatisticsElement* element, int count);
};

#endif /* defined(__iCombos__StatisticsPanel__) */
