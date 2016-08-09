#include "Shield.h"
#include "Classes.h"


Shield::Shield() {
    // TODO Auto-generated constructor stub
}

Shield::~Shield() {
    // TODO Auto-generated destructor stub
}

bool Shield::init() {
    if (!Role::init()) {
        return false;
    }
    
    this->hitCount = 0;
    
    return true;
}

void Shield::updateShape(PhysicsShapeCircle *shape)
{
    shape->setGroup(SHIELD_GROUP);
    shape->setCategoryBitmask(SHIELD_BITMASK_CATEGORY);
    shape->setCollisionBitmask(SHIELD_BITMASK_COLLISION);
    shape->setContactTestBitmask(SHIELD_BITMASK_CONTACT_TEST);
}

std::string Shield::getClassTypeName()
{
    return clazz_Shield;
}

