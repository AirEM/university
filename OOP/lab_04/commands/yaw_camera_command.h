#ifndef YAW_CAMERA_COMMAND_H
#define YAW_CAMERA_COMMAND_H

#include "basecommand.h"
#include "../math/point.h"
#include "../mediator/mediator.h"

namespace commands {

class YawCameraCommand: public BaseCommand {
public:
    YawCameraCommand(std::string object_name, double angle);
    void execute(std::shared_ptr<Mediator> mediator) override;
private:
    std::string _object_name;
    math::Point _rotation;
};

} // namespace commands

#endif // YAW_CAMERA_COMMAND_H
