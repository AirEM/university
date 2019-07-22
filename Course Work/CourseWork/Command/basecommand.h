#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <memory>

#include "../Mediator/mediator.h"
#include "../Geometry/vector3d.h"

namespace command {

using mediator::Mediator;
using geometry::Vector3d;

class BaseCommand
{
public:
    virtual void execute(std::shared_ptr<Mediator> mediator) = 0;
    virtual ~BaseCommand() = default;
};

}

#endif // BASECOMMAND_H
