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
    Facade() = default;
    ~Facade() = default;

    void execute(BaseCommand *command);

private:
    static std::shared_ptr<Mediator> _mediator;

    Facade(const Facade& root) = delete;
    Facade& operator=(const Facade&) = delete;

};

}

#endif // FACADE_H
