#ifndef MOVECAMERACOMMAND_H
#define MOVECAMERACOMMAND_H

#include "basecommand.h"

namespace command {

class MoveCameraCommand : public BaseCommand
{
public:
    MoveCameraCommand(float, float, float);
    void execute(std::shared_ptr<Mediator> mediator) override;

private:
    float _dx;
    float _dy;
    float _dz;
};

}

#endif // MOVECAMERACOMMAND_H
