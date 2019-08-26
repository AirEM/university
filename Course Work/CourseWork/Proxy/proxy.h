#ifndef IDMAKER_H
#define IDMAKER_H

#include <memory>

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

    int CreateSphere();
    int CreateMainLight();

private:
    static int _light_id;
    static int _figure_id;

    std::unique_ptr<Facade> _facade;

    Proxy(const Proxy&);
    Proxy& operator=(const Proxy&);
};

}

#endif // IDMAKER_H
