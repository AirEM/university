#ifndef LAB4_RENDERER_H
#define LAB4_RENDERER_H

#include <memory>
#include "base_manager.h"
#include "../render/base_drawer.h"
#include "../exceptions/drawer_exception.h"
#include "../scene/scene.h"
#include "../objects/composite/composite.h"
#include "../objects/model/model.h"
#include "../objects/camera/camera.h"
#include "../math/point.h"
#include "../math/transform_matrix.h"

namespace managers {

using namespace math;
using namespace objects;
using render::BaseDrawer;
using scene::Scene;

class RendererManager: public BaseManager {
public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void draw(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<Camera> _camera;

    void proectPoint(Point &point);
};

} // namespace render;

#endif //LAB4_RENDERER_H
