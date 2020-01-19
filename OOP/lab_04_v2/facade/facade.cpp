#include "facade.h"

namespace facade {

Facade::Facade(): _mediator(new Mediator) {}

void Facade::execute(commands::BaseCommand *command) {
    if (!command) {
        return;
    }
    command->execute(_mediator);
}

} // namespace facade
