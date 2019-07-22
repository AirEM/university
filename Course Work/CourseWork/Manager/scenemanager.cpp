#include "scenemanager.h"

namespace manager {

SceneManager::SceneManager() : _scene(new Scene) {}

std::shared_ptr<Scene> SceneManager::getScene() const
{
    return _scene;
}

std::shared_ptr<Camera> SceneManager::getCamera() const
{
    return _scene->getCamera();
}

}
