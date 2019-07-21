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

    auto objs = this->_objects;

    for (size_t i=0; i < objs.size(); i++)
    {
        float dist_i;

        if (objs[i]->ray_intersect(orig, dir, dist_i) && dist_i < dist)
        {
            dist = dist_i;

            hit = orig + (dir * dist_i);

            N = (hit - objs[i]->getCenter()).normalize();

            material = objs[i]->getMaterial();
        }
    }

    float checkerboard_dist = std::numeric_limits<float>::max();

    if ( fabs(dir.getY()) > 1e-3)
    {
        float d = -(orig.getY() + 4) / dir.getY(); // the checkerboard plane has equation y = -4

        Vector3d pt = orig + dir*d;

        if (d>0 && fabs(pt.getX())<10 && pt.getZ()<-10 && pt.getZ()>-30 && d<dist)
        {
            checkerboard_dist = d;
            hit = pt;
            N = Vector3d(0,1,0);

            material.getDiffuse() = (int(.5*hit.getX()+1000) + int(.5*hit.getZ())) & 1 ? Vector3d(1,1,1) : Vector3d(0, 0, 1);
            material.getDiffuse() = material.getDiffuse()*.3;
        }
    }
    return std::min(dist, checkerboard_dist)<1000;
}

}
