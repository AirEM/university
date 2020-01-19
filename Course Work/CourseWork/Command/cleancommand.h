#ifndef CLEANCOMMAND_H
#define CLEANCOMMAND_H

#include "basecommand.h"

namespace command {

class CleanCommand : public BaseCommand
{
public:
    CleanCommand() = default;
    void execute(std::shared_ptr<Mediator>) override;
};

}

#endif // CLEANCOMMAND_H
