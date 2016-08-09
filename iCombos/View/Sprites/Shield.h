#ifndef __iCombos__Shield__
#define __iCombos__Shield__

#include "Role.h"

#define clazz_Shield "Shield"

class Shield: public Role
{
private:
    
    
public:
    
    Shield();
    virtual ~Shield();
    virtual bool init();
    CREATE_FUNC(Shield);
    
    virtual std::string getClassTypeName();
    
    virtual void updateShape(PhysicsShapeCircle* shape);
    
    int hitCount ;
};

#endif /* defined(__iCombos__Shield__) */
