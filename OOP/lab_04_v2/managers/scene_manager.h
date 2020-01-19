#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <memory>
#include "base_manager.h"
#include "../exceptions/camera_lack_exception.h"
#include "../objects/camera/camera.h"
#include "../scene/scene.h"

namespace managers {

using scene::Scene;
using objects::Camera;

class SceneManager: public BaseManager {
public:

    void initScene();
    std::shared_ptr<Scene> getScene();
    void setCurrentCamera(std::string cam_name);
    std::shared_ptr<objects::Camera> getCurrentCamera();
private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<objects::Camera> _current_camera;
};

} // namespace scene

#endif // SCENE_MANAGER_H
