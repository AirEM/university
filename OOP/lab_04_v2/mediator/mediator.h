#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <memory>
#include "../exceptions/object_type_exception.h"
#include "../math/point.h"
#include "../managers/renderer_manager.h"
#include "../managers/transformer_manager.h"
#include "../managers/camera_manager.h"
#include "../download/file_loader.h"
#include "../managers/load_manager.h"
#include "../managers/scene_manager.h"
#include "../managers/scene_builder_manager.h"
#include "../scene/scene.h"
#include "../objects/model/model.h"

namespace mediator {


using namespace managers;

using objects::Object;
using objects::Model;
using objects::Camera;
using scene::Scene;
using render::BaseDrawer;
using math::Point;
using namespace managers;
//using namespace managers;

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
    std::shared_ptr<RendererManager> _renderer_manager;
    LoadManager _load_manager;
    TransformerManager _transformer_manager;
    CameraManager _camera_manager;
    SceneManager _scene_manager;
    SceneBuilderManager _scene_builder_manager;
};

}

#endif // MEDIATOR_H
