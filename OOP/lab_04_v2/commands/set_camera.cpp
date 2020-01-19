#include "set_camera.h"

namespace commands {

SetCameraCommand::SetCameraCommand(std::string name): _name(name) {}

void SetCameraCommand::execute(std::shared_ptr<Mediator> mediator) {
    mediator->setCamera(_name);
}

} // namespace commands
