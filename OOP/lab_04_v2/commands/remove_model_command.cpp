#include "remove_model_command.h"

namespace commands {

RemoveModelCommand::RemoveModelCommand(std::string object_name):
    _object_name(object_name) {}

void RemoveModelCommand::execute(std::shared_ptr<Mediator> mediator) {
    mediator->removeModel(_object_name);
}

} // namespace commands
