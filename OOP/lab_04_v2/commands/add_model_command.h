#ifndef ADD_MODEL_COMMAND_H
#define ADD_MODEL_COMMAND_H

#include <string>
#include "basecommand.h"
#include "../mediator/mediator.h"

namespace commands {

using mediator::Mediator;

class AddModelCommand: public BaseCommand {
public:
    explicit AddModelCommand(std::string file_name, std::string model_name);
    void execute(std::shared_ptr<Mediator> mediator) override;
private:
    std::string _file_name;
    std::string _model_name;
};

} // namespace commands

#endif // ADD_MODEL_COMMAND_H
