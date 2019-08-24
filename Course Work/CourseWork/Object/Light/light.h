#ifndef LIGHT_H
#define LIGHT_H

#include "../../Geometry/vector3d.h"

namespace object {

using geometry::Vector3d;

class Light
{
public:
    Light(const Vector3d&, const float);

    Vector3d getPosition() const;
    float getIntensity() const;

private:
    Vector3d _position;
    float _intensity;
    int _id;
};

}

#endif // LIGHT_H
