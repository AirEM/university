#ifndef ROTATECAMERACOMMAND_H
#define ROTATECAMERACOMMAND_H

#include "basecommand.h"

namespace command {


class RotateCameraCommand : public BaseCommand
{
public:
    RotateCameraCommand(float, float);
    void execute(std::shared_ptr<Mediator>) override;

private:
    float _d_angel_x;
    float _d_angel_y;
};

}

#endif // ROTATECAMERACOMMAND_H
