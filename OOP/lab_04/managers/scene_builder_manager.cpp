#include "scene_builder.h"

#include <memory>

namespace scene {

void SceneBuilder::addModel(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model)
{
    scene->addModel(model);
}

void SceneBuilder::addCamera(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera)
{
    scene->addCamera(camera);
}


void SceneBuilder::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model)
{
    this->addModel(scene, model);
}

void SceneBuilder::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera)
{
    this->addCamera(scene, camera);
}

void SceneBuilder::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model,
                std::shared_ptr<Camera> camera)
{
    this->addModel(scene, model);
    this->addCamera(scene, camera);
}

}
