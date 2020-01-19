#include "rendercommand.h"

namespace command  {

RenderCommand::RenderCommand(int w, int h, std::shared_ptr<BaseDrawer> d) :
    _width(w), _height(h), _drawer(d)
{}


void RenderCommand::execute(std::shared_ptr<Mediator> mediator)
{
    mediator->Render(_width, _height, _drawer);
}

}
