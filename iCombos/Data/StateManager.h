#ifndef __iCombos__StateManager__
#define __iCombos__StateManager__

#include "Interval.h"



#define kState_waveCount "waveCount"
#define kState_spearsCount "spearsCount"
#define kState_shieldsCount "shieldsCount"
#define kState_destroyHits "destroyHits"
#define kState_damagesCount "damagesCount"
#define kState_totalHitsCount "totalHitsCount"


class StateManager
{
private:
    
    
public:
    
    static StateManager* getInstance();
    StateManager();
    virtual ~StateManager();
    virtual bool init();
    
#pragma mark -
    
    int destroyHits;
    int currentWaveSum;
};


#endif /* defined(__iCombos__StateManager__) */
