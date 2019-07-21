#ifndef FACADE_H
#define FACADE_H

#include <memory>

#include "../Command/basecommand.h"
#include "../Mediator/mediator.h"

namespace facade {

using command::BaseCommand;
using mediator::Mediator;

class Facade
{
public:
    Facade();
    void execute(BaseCommand *command);

private:
    std::shared_ptr<Mediator> _mediator;

};

}

#endif // FACADE_H
