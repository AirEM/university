#ifndef ADDCUBECOMMAND_H
#define ADDCUBECOMMAND_H

#include "basecommand.h"

#include "../Object/cube.h"

namespace command {

using object::Cube;
using object::Material;

class AddCubeCommand : public BaseCommand
{
public:
    AddCubeCommand(Vector3d&, Vector3d&, Material&);
    void execute(std::shared_ptr<Mediator> mediator) override;

private:
    Vector3d _min_point, _max_point;
    Material _material;
};

}

#endif // ADDCUBECOMMAND_H
