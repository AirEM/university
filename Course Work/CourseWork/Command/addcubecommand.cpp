#include "addcubecommand.h"

namespace command {

AddCubeCommand::AddCubeCommand(int id, Vector3d& min, Vector3d& max, Material& m) :
    _id(id), _min_point(min), _max_point(max), _material(m) {}

void AddCubeCommand::execute(std::shared_ptr<Mediator> mediator)
{
    auto c = new Cube(_id, _min_point, _max_point, _material);

    std::shared_ptr<Cube> obj(c);

    mediator->AddFigure(obj);
}

}
