#ifndef __iCombos__MainLayer__
#define __iCombos__MainLayer__

#include "Interval.h"

class MainLayer: public LayerGradient
{
private:
    
    
public:
    virtual bool init();
    CREATE_FUNC(MainLayer);
    
    LayerGradient* effectLayer;
};

#endif /* defined(__iCombos__MainLayer__) */
