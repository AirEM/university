#ifndef RENDERCOMMAND_H
#define RENDERCOMMAND_H

#include "basecommand.h"
#include "../Drawer/basedrawer.h"

namespace command {

using drawer::BaseDrawer;

class RenderCommand : public BaseCommand
{
public:
    RenderCommand(int, int, std::shared_ptr<BaseDrawer>);
    void execute(std::shared_ptr<Mediator>) override;

private:
    int _width;
    int _height;

    std::shared_ptr<BaseDrawer> _drawer;
};

}

#endif // RENDERCOMMAND_H
