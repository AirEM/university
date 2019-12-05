#include "proxy.h"


namespace proxy {

int Proxy::_light_id = 1;
int Proxy::_figure_id = 1;

Proxy::Proxy() : _facade(new Facade) {}


int Proxy::CreateLight()
{
    int id = _light_id++;

    LightDialog ld;
    ld.setId(id);
    ld.setModal(true);
    ld.exec();

    if (ld.isCanseled())
    {
        id = -1;
        _light_id--;
    }

    return id;
}

int Proxy::CreateFigure()
{
    int id = _figure_id++;

    FigureDialog fd;
    fd.setId(id);
    fd.setModal(true);
    fd.exec();


    if (fd.isCanseled())
    {
        id = -1;
        _figure_id--;
    }

    return id;
}


int Proxy::CreateMainLight()
{
    int id = _light_id++;

    command::AddLightCommand command(0, 20, -8, 1.2f, id);
    _facade->execute(&command);

    // Добавление освещения
//    command::AddLightCommand command_l(-20, 20,  20, 1.0, 0);
//    _facade->execute(&command_l);

//    command::AddLightCommand command_l1(30, 50, -25, 1.2f, 0);
//    _facade->execute(&command_l1);

//    command::AddLightCommand command_l2(30, 20,  30, 1.0, 0);
//    _facade->execute(&command_l2);

    return id;
}

}
