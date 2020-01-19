#include "rotatecameracommand.h"

namespace command {

RotateCameraCommand::RotateCameraCommand(float angel_x, float angel_y) : _d_angel_x(angel_x), _d_angel_y(angel_y) {}

void RotateCameraCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->TransformCamera(0, 0, 0, _d_angel_x, _d_angel_y);
}

}
