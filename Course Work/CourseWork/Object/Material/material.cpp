#include "material.h"

namespace object {

Material::Material() : _diffuse(), _ambient(1, 0, 0), _specular() {}

Material::Material(const Vector3d &a, const Vector3d &color, const float spec) :
    _diffuse(color), _ambient(a), _specular(spec) {}


Vector3d& Material::getAmbient()
{
    return _ambient;
}

Vector3d& Material::getDiffuse()
{
    return _diffuse;
}

float Material::getSpecular()
{
    return _specular;
}


Material& Material::operator=(const Material& right)
{
    if (this == &right) {
        return *this;
    }

    this->_diffuse = right._diffuse;

    return *this;
}

Material& Material::operator=(Material& right)
{
    if (this == &right) {
        return *this;
    }

    this->_diffuse = right._diffuse;

    return *this;
}

}
