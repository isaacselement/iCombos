#include "Role.h"
#include "Classes.h"

Role::Role() {
    // TODO Auto-generated constructor stub
}

Role::~Role() {
    // TODO Auto-generated destructor stub
}

bool Role::init()
{
    if (!Sprite::init()) {
        return false;
    }
    
    headerSizeMultiple = 1;
    
    particles = ParticleSystemQuad::create(getClassTypeName().append(".plist"));
    particles->setPosition(Vec2(0, 0));
    this->addChild(particles);
    
    RapidjsonNoder::applyParticlsProperties(particles, getConfig()["Particles"]);

    physicsBody = PhysicsBody::createCircle(particles->getStartSize() / 4);
    setPhysicsBody(physicsBody);
    
    PhysicsShapeCircle* shape = (PhysicsShapeCircle*)physicsBody->getShape(0);
    updateShape(shape);

    return true;
}

std::string Role::getClassTypeName()
{
    return clazz_Role;
}

void Role::setHeaderSizeMultiple(float multi)
{
    headerSizeMultiple = multi;
    setHeaderSize(getHeaderSize() * multi);
}

float Role::getHeaderSizeMultiple()
{
    return headerSizeMultiple;
}

void Role::setHeaderSize(float size)
{
    particles->setStartSize(size);
    PhysicsShapeCircle* shape = (PhysicsShapeCircle*)physicsBody->getShape(0);
    physicsBody->removeShape(shape);
    
    shape = PhysicsShapeCircle::create(size / 4);
    physicsBody->addShape(shape);
    
    updateShape(shape);
}
float Role::getHeaderSize()
{
    return particles->getStartSize();
}



void Role::updateShape(PhysicsShapeCircle *shape)
{
}



void Role::removeRoleSelf(float dt)
{
    removeFromParent();
}

void Role::run(float duration, cocos2d::Vec2 source, cocos2d::Vec2 destination)
{
    this->setPosition(source);
    runAction(MoveTo::create(duration, destination));
    
    // Remove it from world
    scheduleOnce(schedule_selector(Role::removeRoleSelf), duration);
}

rapidjson::Value& Role::getConfig()
{
    return DataManager::getInstance()->configs[getClassTypeName().c_str()];
}
