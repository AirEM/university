#include "../managers/scene_builder_manager.h"

#include <memory>

namespace managers {

void SceneBuilderManager::addModel(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model)
{
    scene->addModel(model);
}

void SceneBuilderManager::addCamera(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera)
{
    scene->addCamera(camera);
}


void SceneBuilderManager::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model)
{
    this->addModel(scene, model);
}

void SceneBuilderManager::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Camera> camera)
{
    this->addCamera(scene, camera);
}

void SceneBuilderManager::buildScene(std::shared_ptr<Scene> scene, std::shared_ptr<Model> model,
                std::shared_ptr<Camera> camera)
{
    this->addModel(scene, model);
    this->addCamera(scene, camera);
}

}
