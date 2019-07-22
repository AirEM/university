#ifndef FACADE_H
#define FACADE_H

#include "../mediator/mediator.h"
#include "../commands/basecommand.h"

namespace facade {

using mediator::Mediator;
using namespace commands;

class Facade {
public:
    Facade();
    void execute(BaseCommand *command);
private:
    std::shared_ptr<Mediator> _mediator;
};

} // namespace facade

#endif // FACADE_H
