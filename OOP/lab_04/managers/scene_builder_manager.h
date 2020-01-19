#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include <memory>
#include "../scene/scene.h"
#include "../objects/model.h"
#include "../objects/camera.h"

namespace scene {

using objects::Model;
using objects::Camera;
using scene::Scene;

class SceneBuilder
{
public:
    SceneBuilder() = default;
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
