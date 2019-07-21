#ifndef ADDSPHERECOMMAND_H
#define ADDSPHERECOMMAND_H

#include "basecommand.h"
#include "../Object/sphere.h"

namespace command {

using object::Sphere;
using object::BaseObject;
using object::Material;

class AddSphereCommand : public BaseCommand
{
public:
    AddSphereCommand(float, float, float, size_t, Material);
    void execute(std::shared_ptr<Mediator> mediator) override;

private:
    float _x_centre, _y_centre, _z_centre;
    size_t _radius;
    Material _material;
};

}

#endif // ADDSPHERECOMMAND_H
