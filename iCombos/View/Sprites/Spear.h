#ifndef __iCombos__Spear__
#define __iCombos__Spear__

#include "Role.h"

#define clazz_Spear "Spear"

class Spear: public Role
{
private:
    
    
public:
    Spear();
    virtual ~Spear();
    virtual bool init();
    CREATE_FUNC(Spear);
    
    virtual std::string getClassTypeName();
    
    virtual void updateShape(PhysicsShapeCircle* shape);
};

#endif /* defined(__iCombos__Spear__) */
