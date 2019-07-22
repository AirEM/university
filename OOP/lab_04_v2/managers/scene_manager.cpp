#include "../managers/scene_manager.h"

namespace managers {


void SceneManager::initScene()
{
    auto sc = new Scene;
    std::shared_ptr<Scene> sc_ptr(sc);
    this->_scene = sc_ptr;
}

std::shared_ptr<Scene> SceneManager::getScene() {
    return _scene;
}

void SceneManager::setCurrentCamera(std::string cam_name) {
    _current_camera = _scene->getCamera(cam_name);
}

std::shared_ptr<Camera> SceneManager::getCurrentCamera() {
    if (!_current_camera) {
        throw exceptions::CameraLackException();
    }
    return _current_camera;
}

} // namespace scene
