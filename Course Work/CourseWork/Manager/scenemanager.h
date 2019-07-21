#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Scene/scene.h"

namespace manager {

using scene::Scene;
using camera::Camera;

class SceneManager
{
public:
    SceneManager();

    std::shared_ptr<Scene> getScene() const;
    std::shared_ptr<Camera> getCamera() const;

private:
    std::shared_ptr<Scene> _scene;
};

}

#endif // SCENEMANAGER_H
