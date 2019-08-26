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

    return id;
}

int Proxy::CreateFigure()
{
    int id = _figure_id++;

    FigureDialog fd;
    fd.setId(id);
    fd.setModal(true);
    fd.exec();

    return id;
}


int Proxy::CreateMainLight()
{
    int id = _light_id++;

    command::AddLightCommand command(0, 20,  20, 1.0, id);
    _facade->execute(&command);

    return id;
}

}
