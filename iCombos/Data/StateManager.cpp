#include "StateManager.h"
#include "Classes.h"

static StateManager* s_sharedStateManager = nullptr;
StateManager* StateManager::getInstance()
{
    if (!s_sharedStateManager) {
        s_sharedStateManager = new (std::nothrow) StateManager();
        CCASSERT(s_sharedStateManager, "Fatal: no enough memory");
        s_sharedStateManager->init();
    }
    return s_sharedStateManager;
}

StateManager::StateManager()
{
    
}

StateManager::~StateManager()
{
    
}

bool StateManager::init()
{
    this->destroyHits = 0;
    this->currentWaveSum = 0;
    
    return true;
}


#pragma mark -


