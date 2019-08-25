#include "deletelightcommand.h"

namespace command  {

DeleteLightCommand::DeleteLightCommand(int id) : _id(id) {}


void DeleteLightCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->DeleteLight(_id);
}

}
