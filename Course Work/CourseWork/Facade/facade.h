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

    static Facade& Instance()
    {
        static Facade theSingleInstance;
        return theSingleInstance;
    }

    void execute(BaseCommand *command);

private:
    static std::shared_ptr<Mediator> _mediator;

    Facade(){}
    Facade(const Facade& root) = delete;
    Facade& operator=(const Facade&) = delete;

};

}

#endif // FACADE_H
