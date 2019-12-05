#ifndef ADDCONECOMMAND_H
#define ADDCONECOMMAND_H

#include "basecommand.h"

#include "../Object/cone.h"

namespace command {

using object::Cone;
using object::Material;

class AddConeCommand : public BaseCommand
{
public:
    AddConeCommand(int, Vector3d&, int, int, Material&);
    void execute(std::shared_ptr<Mediator> mediator) override;

private:
    int _id;
    Vector3d _centre;
    int _height;
    int _rad;
    Material _material;
};

}

#endif // ADDCONECOMMAND_H
