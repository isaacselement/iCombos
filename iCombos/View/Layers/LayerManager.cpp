#include "LayerManager.h"
#include "Classes.h"


static MainLayer* mainLayer = nullptr;
MainLayer* LayerManager::getMainLayer()
{
    if (mainLayer == nullptr) {
        mainLayer = MainLayer::create();
        mainLayer->addChild(getStatisticsPanel());
    }
    return mainLayer;
}

static StatisticsPanel* statisticsPanel = nullptr;
StatisticsPanel* LayerManager::getStatisticsPanel()
{
    if (statisticsPanel == nullptr) {
        statisticsPanel = StatisticsPanel::create();
    }
    return statisticsPanel;
}
