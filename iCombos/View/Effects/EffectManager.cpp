#include "EffectManager.h"
#include "Classes.h"


void EffectManager::explodeEffect()
{
    // Play audio
    AudionManager::getInstance()->playStartGameAudio();
    
    // explode effect
    ParticleSystemQuad *system = ParticleSystemQuad::create("Explosion.plist");
    system->setPosition(VecHelper::getWindowCenter());
    system->setAutoRemoveOnFinish(true);
    LayerManager::getMainLayer()->addChild(system);
}


void EffectManager::hitEffect(cocos2d::Vec2 position, float multi)
{
    // Play audio
    AudionManager::getInstance()->playExplosionAudio();
    
    // explode effect
    ParticleSystemQuad *system = ParticleSystemQuad::create("Shield_Hit.plist");
    system->setTotalParticles(system->getTotalParticles() * multi);
    system->setPosition(position);
    LayerManager::getMainLayer()->addChild(system);
}


void EffectManager::startRainEffect(int tag)
{
    ParticleSystemQuad* rainSystem = ParticleSystemQuad::create("Rain.plist");
    rainSystem->setScaleX(3);
    Size winSize = Director::getInstance()->getWinSize();
    rainSystem->setPosition(Vec2(CanvasX(250), winSize.height));
    rainSystem->setTag(tag);
    LayerManager::getMainLayer()->addChild(rainSystem);
}

void EffectManager::remvoveRainEffect(int tag)
{
    LayerManager::getMainLayer()->removeChildByTag(tag);
}

