#ifndef __iCombos__LayerManager__
#define __iCombos__LayerManager__

#include "Interval.h"

class MainLayer;
class StatisticsPanel;

class LayerManager
{
public:
    static MainLayer* getMainLayer();
    static StatisticsPanel* getStatisticsPanel();
};

#endif /* defined(__iCombos__LayerManager__) */
