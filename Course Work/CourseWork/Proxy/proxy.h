#ifndef IDMAKER_H
#define IDMAKER_H

#include <memory>

#include "../UI/lightdialog.h"
#include "../UI/figuredialog.h"
#include "../UI/cameradialog.h"

#include "Facade/facade.h"

#include "Command/addlightcommand.h"

namespace proxy {

using facade::Facade;

using command::AddLightCommand;

class Proxy
{
public:
    Proxy();
    ~Proxy() = default;

    void showCameraDialog();

    int CreateLight();
    int CreateFigure();

    int CreateMainLight();

private:
    static int _light_id;
    static int _figure_id;

    std::shared_ptr<Facade> _facade;

    Proxy(const Proxy&);
    Proxy& operator=(const Proxy&);
};

}

#endif // IDMAKER_H
