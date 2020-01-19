#ifndef ROLL_CAMERA_COMMAND_H
#define ROLL_CAMERA_COMMAND_H

#include "basecommand.h"
#include "math/point.h"
#include "../mediator/mediator.h"

namespace commands {

class RollCameraCommand: public BaseCommand {
public:
    RollCameraCommand(std::string object_name, double angle);
    void execute(std::shared_ptr<Mediator> mediator) override;
private:
    std::string _object_name;
    math::Point _rotation;
};

} // namespace commands

#endif // ROLL_CAMERA_COMMAND_H
