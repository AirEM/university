#include "addlightcommand.h"

namespace command {

AddLightCommand::AddLightCommand(float x, float y, float z, float i) :
    _x_centre(x), _y_centre(y), _z_centre(z), _intensity(i) {}

void AddLightCommand::execute(std::shared_ptr<Mediator> mediator)
{
    Vector3d position(_x_centre, _y_centre, _z_centre);

    auto l = new Light(position, _intensity);

    std::shared_ptr<Light> obj(l);

    mediator->AddLight(obj);

}

}
