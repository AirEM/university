#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>
#include <limits>

#include "../Camera/camera.h"
#include "../Object/baseobject.h"
#include "../Object/Light/light.h"

namespace scene {

using camera::Camera;
using namespace object;

class Scene
{
public:
    Scene();

    std::vector<std::shared_ptr<Light>> getLights() const;
    std::shared_ptr<Camera> getCamera() const;
    std::vector<std::shared_ptr<BaseObject>> getObjects() const;

    void addLight(std::shared_ptr<Light>);
    void addFigure(std::shared_ptr<BaseObject>);

    void deleteLight(int);
    void deleteFigure(int);

    void clean();

    bool intersect(const Vector3d &orig, const Vector3d &dir,
                   Vector3d &hit, Vector3d &N, Material &material);

private:
    std::vector<std::shared_ptr<Light>> _lights;
    std::shared_ptr<Camera> _camera;
    std::vector<std::shared_ptr<BaseObject>> _objects;
};

}

#endif // SCENE_H
