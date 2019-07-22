#include "facade.h"

namespace facade {

Facade::Facade() : _mediator(new Mediator) {}

void Facade::execute(BaseCommand *command)
{
    if (command)
        command->execute(this->_mediator);
}

}
