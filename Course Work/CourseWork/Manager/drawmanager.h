#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <memory>

#include "../Manager/basemanager.h"
#include "../Drawer/basedrawer.h"
#include "../Scene/scene.h"

namespace manager {

using drawer::BaseDrawer;
using scene::Scene;
using object::BaseObject;
using object::Material;
using geometry::Vector3d;

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;

    void setSize(int, int);
    void setDrawer(std::shared_ptr<BaseDrawer>);

    void render(std::shared_ptr<Scene>&);

private:
    Vector3d cast_ray(const Vector3d &, const Vector3d &, const std::shared_ptr<Scene> &);
    Vector3d reflect(const Vector3d &, const Vector3d &);

    int _width;
    int _height;

    std::shared_ptr<BaseDrawer> _drawer;
};

}

#endif // DRAWMANAGER_H
