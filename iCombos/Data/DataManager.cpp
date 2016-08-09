#include "DataManager.h"
#include "Classes.h"

static DataManager* s_sharedDataManager = nullptr;
DataManager* DataManager::getInstance()
{
    if (!s_sharedDataManager) {
        s_sharedDataManager = new (std::nothrow) DataManager();
        CCASSERT(s_sharedDataManager, "Fatal: no enough memory");
        s_sharedDataManager->init();
    }
    return s_sharedDataManager;
}

DataManager::DataManager()
{
    
}

DataManager::~DataManager()
{
    
}

bool DataManager::init()
{
    RapidjsonWrapper::getDocumentByFile(configs, "config.json");
    
    return true;
}

