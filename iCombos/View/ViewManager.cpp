#include "ViewManager.h"
#include "Classes.h"

static Scene* mainScene = nullptr;
Scene* ViewManager::getMainScene()
{
    if (mainScene == nullptr) {
        mainScene = Scene::createWithPhysics();
        mainScene->getPhysicsWorld()->setGravity(Vect(0.0f, 0.0f));
        mainScene->addChild(LayerManager::getMainLayer());
    }
//    mainScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    return mainScene;
}

Color3B ViewManager::getRandomColor()
{
    return Color3B(RANDOM(0, 255), RANDOM(0, 255), RANDOM(0, 255));
}

