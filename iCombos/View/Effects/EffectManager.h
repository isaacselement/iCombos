#ifndef __iCombos__EffectManager__
#define __iCombos__EffectManager__

#include "Interval.h"

class EffectManager
{
private:
    
    
public:
    
    static void explodeEffect();
    
    
    static void hitEffect(Vec2 position, float multi);
    
    
    static void startRainEffect(int tag);
    static void remvoveRainEffect(int tag);
};

#endif /* defined(__iCombos__EffectManager__) */
