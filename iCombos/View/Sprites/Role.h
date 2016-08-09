#ifndef iCombos_Role_h
#define iCombos_Role_h

#include "Interval.h"

#define clazz_Role "Role"

class Role: public Sprite
{
private:
    
    
protected:
    
    
    rapidjson::Value& getConfig();
    
    float headerSizeMultiple;
    void setHeaderSize(float size);
    float getHeaderSize();
    
    
public:
    
    Role();
    virtual ~Role();
    CREATE_FUNC(Role);
    virtual bool init();

    ParticleSystemQuad* particles;
    
    virtual void removeRoleSelf(float dt);
    
    void run(float duration, cocos2d::Vec2 source, cocos2d::Vec2 destination);
    
    PhysicsBody* physicsBody;
    
    virtual std::string getClassTypeName();
    
    void setHeaderSizeMultiple(float multi);
    
    float getHeaderSizeMultiple();
    
    virtual void updateShape(PhysicsShapeCircle* shape);
};


#endif
