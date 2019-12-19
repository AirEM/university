#include "scene.h"

#include <iostream>

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

void Scene::addFigure(std::shared_ptr<BaseObject> obj)
{
    _objects.push_back(obj);
}


void Scene::deleteLight(int id)
{
    auto end_iterator = _lights.end();

    for (auto iter = _lights.begin(); iter != end_iterator; iter++)
    {
        if ((*iter)->getId() == id)
        {
            _lights.erase(iter);
            break;
        }
    }
}


void Scene::deleteFigure(int id)
{
    auto end_iterator = _objects.end();

    for (auto iter = _objects.begin(); iter != end_iterator; iter++)
    {
        if ((*iter)->getID() == id)
        {
            _objects.erase(iter);
            break;
        }
    }
}


void Scene::clean()
{
    auto cur_size = _lights.size();
    for (size_t i = 1; i < cur_size; ++i)
        _lights.pop_back();

    _objects.clear();
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

            N = objs[i]->getNormal(hit);

            material = objs[i]->getMaterial();
        }
    }

    // Работа с видимой горизонтальной плоскостью (Сцена)

    // TODO Вынести сцену(шахматную доску) в отделтный класс, унаследованный от BaseObject
    // данный код убрать в ray_intersect


    float checkerboard_dist = std::numeric_limits<float>::max();

    if (fabs(static_cast<double>(dir.getY())) > 1e-3)
    {
        float d = -(orig.getY()) / dir.getY(); // the checkerboard plane has equation y = -4

        Vector3d pt = orig + dir*d;

        if (d > 0 && dist > d && fabs(pt.getX()) < 10 && pt.getZ() < 0 && pt.getZ() > -20)
        {
            checkerboard_dist = d;

            hit = pt;

            if (orig.getY() >= 0)
                N = Vector3d(0,1,0);
            else
                N = Vector3d(0,-1,0);

            material.getDiffuse() = (int(0.5f * hit.getX() + 1000) + int(0.5f * hit.getZ())) & 1 ?
                        Vector3d(0.3f, 0.3f, 0.3f)  :
                        Vector3d(0.3f, 0.2f, 0.1f);
        }
    }

    return std::min(dist, checkerboard_dist) < 1000;
}

bool Scene::intersect(const Vector3d &orig, const Vector3d &dir,
                      Vector3d &hit, Vector3d &N)
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

            N = objs[i]->getNormal(hit);
        }
    }

    // Работа с видимой горизонтальной плоскостью (Сцена)

    // TODO Вынести сцену(шахматную доску) в отделтный класс, унаследованный от BaseObject
    // данный код убрать в ray_intersect

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

        }
    }

    return std::min(dist, scene_dist)<1000;
}

}
