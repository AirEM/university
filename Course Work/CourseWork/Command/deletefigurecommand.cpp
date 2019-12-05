#include "deletefigurecommand.h"

namespace command  {

DeleteFigureCommand::DeleteFigureCommand(int id) : _id(id) {}


void DeleteFigureCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->DeleteFigure(_id);
}

}
