#include "proxy.h"

namespace proxy {

int Proxy::_light_id = 1;
int Proxy::_figure_id = 1;

Proxy::Proxy() : _facade(new Facade) {}

int Proxy::CreateSphere()
{
    return 0;
}


int Proxy::CreateMainLight()
{
    int id = _light_id++;

    command::AddLightCommand command(0, 20,  20, 1.0, id);
    _facade->execute(&command);

    return id;
}

}
