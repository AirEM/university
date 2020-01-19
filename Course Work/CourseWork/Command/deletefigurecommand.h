#ifndef DELETEFIGURECOMMAND_H
#define DELETEFIGURECOMMAND_H

#include "basecommand.h"

namespace command {

class DeleteFigureCommand : public BaseCommand
{
public:
    DeleteFigureCommand(int);
    void execute(std::shared_ptr<Mediator>) override;

private:
    int _id;
};

}


#endif // DELETEFIGURECOMMAND_H
