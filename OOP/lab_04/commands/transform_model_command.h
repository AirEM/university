#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "basecommand.h"
#include "../math/point.h"
#include "../mediator/mediator.h"

namespace commands {

using mediator::Mediator;
using math::Point;

class TransformModelCommand: public BaseCommand {
public:
    TransformModelCommand(std::string object_name, Point move, Point scale, Point rotate);
    void execute(std::shared_ptr<Mediator> mediator) override;
private:
    std::string _object_name;
    Point _move;
    Point _scale;
    Point _rotate;
};

} // namespace commands

#endif // MOVE_COMMAND_H
