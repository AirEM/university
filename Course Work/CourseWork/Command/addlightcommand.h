#ifndef ADDLIGHTCOMMAND_H
#define ADDLIGHTCOMMAND_H

#include "basecommand.h"

#include "../Object/Light/light.h"


namespace command {

using object::Light;

class AddLightCommand : public BaseCommand
{
public:
    AddLightCommand(float, float, float, float);
    void execute(std::shared_ptr<Mediator> mediator) override;

private:
    float _x_centre, _y_centre, _z_centre;
    float _intensity;
};

}

#endif // ADDLIGHTCOMMAND_H
