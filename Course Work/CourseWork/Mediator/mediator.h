#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "../Object/baseobject.h"
#include "../Manager/scenemanager.h"
#include "../Manager/drawmanager.h"
#include "../Drawer/basedrawer.h"

namespace mediator {

using object::BaseObject;
using object::Light;
using manager::SceneManager;
using manager::DrawManager;
using drawer::BaseDrawer;

class Mediator
{
public:
    Mediator();

    void AddFigure(std::shared_ptr<BaseObject>);
    void AddLight(std::shared_ptr<Light>);
    void DeleteLight(int);
    void DeleteFigure(int);
    void Clean();
    void Render(int, int, std::shared_ptr<BaseDrawer>);

private:
    std::shared_ptr<SceneManager> _scene_manager;
    std::shared_ptr<DrawManager> _draw_manager;

};

}

#endif // MEDIATOR_H
