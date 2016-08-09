#ifndef __iCombos__DataManager__
#define __iCombos__DataManager__

#include "Interval.h"

class DataManager
{
private:
    
    
public:
    
    static DataManager* getInstance();
    
    DataManager();
    virtual ~DataManager();
    virtual bool init();
    
    rapidjson::Document configs;
    
};

#endif /* defined(__iCombos__DataManager__) */
