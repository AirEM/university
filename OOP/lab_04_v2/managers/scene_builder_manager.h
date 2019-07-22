#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include <memory>
#include "base_manager.h"
#include "../scene/scene.h"
#include "../objects/model/model.h"
#include "../objects/camera/camera.h"

namespace managers {

using objects::Model;
using objects::Camera;
using scene::Scene;

class SceneBuilderManager: public BaseManager
{
public:
    SceneBuilderManager() = default;
    void buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model);
    void buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera);
    void buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model,
                    std::shared_ptr<Camera> camera);

private:
    void addModel(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model);
    void addCamera(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera);
};

}

#endif // SCENEBUILDER_H
