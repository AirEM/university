#include "facade.h"

namespace facade {

std::shared_ptr<Mediator> Facade::_mediator(new Mediator);

void Facade::execute(BaseCommand *command)
{
    if (command)
        command->execute(_mediator);
}

}
