#include "add_camera_command.h"

namespace commands {

AddCameraCommand::AddCameraCommand(std::string name): _name(name) {}

void AddCameraCommand::execute(std::shared_ptr<Mediator> mediator) {
    mediator->addCamera(_name);
}

} // namespace commands
