#include "mediator.h"

namespace mediator {

Mediator::Mediator() :
    _scene_manager(new SceneManager),
    _draw_manager(new DrawManager)
{}


void Mediator::AddFigure(std::shared_ptr<BaseObject> obj)
{
    auto scene = _scene_manager->getScene();

    scene->addFigure(obj);
}

void Mediator::AddLight(std::shared_ptr<Light> obj)
{
    auto scene = _scene_manager->getScene();
    scene->addLight(obj);
}


void Mediator::DeleteLight(int id)
{
    auto scene = _scene_manager->getScene();
    scene->deleteLight(id);
}

void Mediator::DeleteFigure(int id)
{
    auto scene = _scene_manager->getScene();
    scene->deleteFigure(id);
}


void Mediator::TransformCamera(float dx, float dy, float dz, float angle_x, float angle_y)
{
    auto camera = _scene_manager->getScene()->getCamera();

    camera->moveCamera(dx, dy, dz);

    camera->rotateCamera(angle_x, angle_y);
}


void Mediator::Clean()
{
    auto scene = _scene_manager->getScene();
    scene->clean();
}


void Mediator::Render(int width, int height, std::shared_ptr<BaseDrawer> drawer)
{
    _draw_manager->setSize(width, height);
    _draw_manager->setDrawer(drawer);

    auto scene = _scene_manager->getScene();

    _draw_manager->render(scene);
}

}
