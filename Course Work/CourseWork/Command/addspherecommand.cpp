#include "addspherecommand.h"

namespace command {

AddSphereCommand::AddSphereCommand(float x, float y, float z, size_t r, Material m) :
    _x_centre(x), _y_centre(y), _z_centre(z), _radius(r), _material(m)
{}

void AddSphereCommand::execute(std::shared_ptr<Mediator> mediator)
{
    Vector3d centre(_x_centre, _y_centre, _z_centre);
    auto s = new Sphere(centre, _radius, _material);

    std::shared_ptr<Sphere> obj(s);

    mediator->AddFigure(obj);

}

}
