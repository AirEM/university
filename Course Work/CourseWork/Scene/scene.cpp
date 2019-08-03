#include "scene.h"

namespace scene {

Scene::Scene() : _camera(new Camera) {}


std::vector<std::shared_ptr<Light>> Scene::getLights() const
{
    return _lights;
}

std::shared_ptr<Camera> Scene::getCamera() const
{
    return _camera;
}

std::vector<std::shared_ptr<BaseObject>> Scene::getObjects() const
{
    return _objects;
}


void Scene::addLight(std::shared_ptr<Light> obj)
{
    _lights.push_back(obj);
}


void Scene::addObject(std::shared_ptr<BaseObject> obj)
{
    _objects.push_back(obj);
}


bool Scene::intersect(const Vector3d &orig, const Vector3d &dir,
                      Vector3d &hit, Vector3d &N, Material &material)
{
    float dist = std::numeric_limits<float>::max();

    // Работа с объетами на сцене

    auto objs = this->_objects;

    for (size_t i=0; i < objs.size(); i++)
    {
        float dist_i;

        if (objs[i]->ray_intersect(orig, dir, dist_i) && dist_i < dist)
        {
            dist = dist_i;

            hit = orig + (dir * dist_i);

            // Нужно заменить на getNormal() (Функция должна быть объвлена в абстрактном классе BaseObject)
            N = (hit - objs[i]->getCenter()).normalize();

            material = objs[i]->getMaterial();
        }
    }

    // Работа с видимой горизонтальной плоскостью (Сцена)

    float scene_dist = std::numeric_limits<float>::max();

    if ( fabs(dir.getY()) > 1e-3)
    {
        float d = -(orig.getY() + 4) / dir.getY(); // the checkerboard plane has equation y = -4

        Vector3d pt = orig + dir*d;

        if (d > 0 && fabs(pt.getX()) < 10 && pt.getZ()< -10 && pt.getZ() > -30 && d < dist)
        {
            scene_dist = d;
            hit = pt;
            N = Vector3d(0,1,0);

            // Vector3d(0.98f,0.835f,0.117f) Vector3d(0.741f,0.854f,0.341f)

            material.getDiffuse() = (int(.5*hit.getX()+1000) + int(.5*hit.getZ())) & 1 ?
                        Vector3d(0.98f,0.835f,0.117f)  :
                        Vector3d(0.741f,0.854f,0.341f);
        }
    }

    return std::min(dist, scene_dist)<1000;
}

}
