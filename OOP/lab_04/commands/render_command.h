#ifndef LAB4_RENDERCOMMAND_H
#define LAB4_RENDERCOMMAND_H

#include "basecommand.h"
#include "../mediator/mediator.h"

namespace commands {

using mediator::Mediator;

class RenderCommand: public BaseCommand {
public:
    explicit RenderCommand(std::shared_ptr<render::BaseDrawer> drawer);
    void execute(std::shared_ptr<Mediator> mediator) override;
private:
    std::shared_ptr<render::BaseDrawer> _drawer;
};

} // namespace commands

#endif //LAB4_RENDERCOMMAND_H
