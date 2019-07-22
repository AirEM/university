#include "light.h"

namespace object {

Light::Light(const Vector3d &p, const float i) : _position(p), _intensity(i) {}


Vector3d Light::getPosition() const
{
    return _position;
}

float Light::getIntensity() const
{
    return _intensity;
}

}
