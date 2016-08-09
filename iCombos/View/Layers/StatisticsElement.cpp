#include "StatisticsElement.h"
#include "Classes.h"

bool StatisticsElement::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    keyLabel = Label::create();
    this->addChild(keyLabel);
    
    
    valueLabel = Label::create();
    this->addChild(valueLabel);
    
    return true;
}
