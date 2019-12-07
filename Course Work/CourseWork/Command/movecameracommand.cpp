#include "movecameracommand.h"

namespace command {

MoveCameraCommand::MoveCameraCommand(float x, float y, float z) : _dx(x), _dy(y), _dz(z) {}

void MoveCameraCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->TransformCamera(_dx, _dy, _dz, 0, 0);
}


}
