#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <memory>
#include "../exceptions/object_type_exception.h"
#include "../math/point.h"
#include "../render/renderer.h"
#include "../transformations/transformer.h"
#include "../transformations/camera_manager.h"
#include "../uploading/file_loader.h"
#include "../uploading/load_manager.h"
#include "../scene/scene_manager.h"
#include "../scene/scene_builder.h"
#include "../objects/model.h"

namespace mediator {

using objects::Object;
using objects::Model;
using objects::Camera;
using scene::Scene;
using render::BaseDrawer;
using math::Point;

class Mediator {
public:
    Mediator();

    void addModel(std::string file_name, std::string model_name);
    void addCamera(std::string cam_name);
    void setCamera(std::string cam_name);
    void removeCamera(std::string cam_name);
    void removeModel(std::string model_name);

    void transformCamera(std::string cam_name, Point &move, Point &rotate);
    void transformModel(std::string model_name, Point &move, Point &scale, Point &rotate);

    void draw(std::shared_ptr<BaseDrawer> drawer);
private:
    std::shared_ptr<render::Renderer> _renderer;
    uploading::LoadManager _loader;
    transformations::Transformer _transformer;
    transformations::CameraManager _cam_manager;
    scene::SceneManager _scene_manager;
    scene::SceneBuilder _scene_builder;
};

}

#endif // MEDIATOR_H
