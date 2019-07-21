#include "mediator.h"

namespace mediator {

Mediator::Mediator():
    _renderer(new render::Renderer),
    _loader(new uploading::FileLoader)
{
 this->_scene_manager.initScene();
}

void Mediator::addModel(std::string file_name, std::string name) {
    std::shared_ptr<Model> model = _loader.loadModel(file_name, name);
    std::shared_ptr<Scene> scene = _scene_manager.getScene();

    _scene_builder.buildScene(scene, model);
}

void Mediator::addCamera(std::string name) {
    auto camera = new Camera(name);
    std::shared_ptr<Camera> camera_ptr(camera);
    std::shared_ptr<Scene> scene = _scene_manager.getScene();

    _scene_builder.buildScene(scene, camera_ptr);
}

void Mediator::setCamera(std::string cam_name) {
    _scene_manager.setCurrentCamera(cam_name);
}

void Mediator::removeCamera(std::string cam_name) {
    _scene_manager.getScene()->removeCamera(cam_name);
}

void Mediator::removeModel(std::string model_name) {
    auto scene = _scene_manager.getScene();
    scene->removeModel(scene->getObject(model_name));
}

void Mediator::transformCamera(std::string cam_name, math::Point &move, math::Point &rotate) {
    auto camera = _scene_manager.getScene()->getCamera(cam_name);
    _transformer.moveObject(camera, move.x(), move.y(), move.z());
    _cam_manager.roll(camera, rotate.x());
    _cam_manager.pitch(camera, rotate.y());
    _cam_manager.yaw(camera, rotate.z());
}

void Mediator::transformModel(std::string model_name, math::Point &move, math::Point &scale, math::Point &rotate) {
    auto obj = _scene_manager.getScene()->getObject(model_name);
    _transformer.moveObject(obj, move.x(), move.y(), move.z());
    _transformer.scaleObject(obj, scale.x(), scale.y(), scale.z());
    _transformer.rotateObjectX(obj, rotate.x());
    _transformer.rotateObjectY(obj, rotate.y());
    _transformer.rotateObjectZ(obj, rotate.z());
}

void Mediator::draw(std::shared_ptr<BaseDrawer> drawer) {
    _renderer->setDrawer(drawer);
    _renderer->setCamera(_scene_manager.getCurrentCamera());

    _renderer->draw(_scene_manager.getScene());

}

} // namespace intermediary
