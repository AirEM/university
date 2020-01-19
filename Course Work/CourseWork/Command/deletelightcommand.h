#ifndef DELETELIGHTCOMMAND_H
#define DELETELIGHTCOMMAND_H

#include "basecommand.h"

namespace command {

class DeleteLightCommand : public BaseCommand
{
public:
    DeleteLightCommand(int);
    void execute(std::shared_ptr<Mediator>) override;

private:
    int _id;
};

}

#endif // DELETELIGHTCOMMAND_H
