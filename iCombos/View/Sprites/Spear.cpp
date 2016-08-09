#include "Spear.h"
#include "Classes.h"

Spear::Spear() {
    // TODO Auto-generated constructor stub
}

Spear::~Spear() {
    // TODO Auto-generated destructor stub
}

bool Spear::init() {
    if (!Role::init()) {
        return false;
    }

    return true;
}

void Spear::updateShape(PhysicsShapeCircle *shape)
{
    shape->setGroup(SPEAR_GROUP);
    shape->setCategoryBitmask(SPEAR_BITMASK_CATEGORY);
    shape->setCollisionBitmask(SPEAR_BITMASK_COLLISION);
    shape->setContactTestBitmask(SPEAR_BITMASK_CONTACT_TEST);
}

std::string Spear::getClassTypeName()
{
    return clazz_Spear;
}

