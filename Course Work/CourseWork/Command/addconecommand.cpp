#include "addconecommand.h"

namespace command {

AddConeCommand::AddConeCommand(Vector3d& c, int h, int r, Material& m)
    : _centre(c), _height(h), _rad(r), _material(m) {}


void AddConeCommand::execute(std::shared_ptr<Mediator> mediator)
{
    auto c = new Cone(_centre, _height, _rad, _material);

    std::shared_ptr<Cone> obj(c);

    mediator->AddFigure(obj);
}

}
