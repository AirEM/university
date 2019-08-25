#include "light.h"

namespace object {

Light::Light(const Vector3d &p, const float i, const int id) : _position(p), _intensity(i), _id(id) {}


Vector3d Light::getPosition() const
{
    return _position;
}

float Light::getIntensity() const
{
    return _intensity;
}

int Light::getId() const
{
    return _id;
}


}
