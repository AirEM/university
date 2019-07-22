#include "pitch_camera_command.h"

namespace commands {

PitchCameraCommand::PitchCameraCommand(std::string object_name, double angle):
    _object_name(object_name), _rotation(0, angle, 0) {}

void PitchCameraCommand::execute(std::shared_ptr<Mediator> mediator) {
    math::Point moving(0, 0, 0);
    mediator->transformCamera(_object_name, moving, _rotation);
}

} // namespace commands
