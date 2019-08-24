#include "cleancommand.h"

namespace command  {

void CleanCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->Clean();
}

}

