#ifndef __iCombos__EventManager__
#define __iCombos__EventManager__

#include "Interval.h"

class Role;
class Spear;
class Shield;
class StatisticsElement;

class EventManager
{
public:
    
    static bool isGameStarted;
    
#pragma mark -
    
    static EventManager* getInstance();
    bool init();
    
#pragma mark - Touch Event
    
    bool onTouchBegan(Touch *touch, Event *unused_event);
    void onTouchMoved(Touch *touch, Event *unused_event);
    void onTouchEnded(Touch *touch, Event *unused_event);
    
#pragma mark -
    
    void launchGame();
    void startGame();
    void pauseGame();
    void finishGame();
    void timesOverEvent();
    
    void fallEvent();
    void shootEvent(Vec2 location);
    void hitEvent(Spear* spear, Shield* shield, Vec2 location);
    

    void setHitRateValueToPanel();
    void getHitRateValueToPanel();
    
    void setStatisticsValueToPanel(StatisticsElement* ele, const char* stateKey);
    void getStatisticsValueToPanel(StatisticsElement* ele, const char* stateKey);
    
    int setStatisticsValue(const char* stateKey);
    int getStatisticsValue(const char* stateKey);
    
};

#endif /* defined(__iCombos__EventManager__) */

