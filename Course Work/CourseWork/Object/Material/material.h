#ifndef MATERIAL_H
#define MATERIAL_H

#include "../../Geometry/vector3d.h"

//TODO Модель фонга

namespace object {

using geometry::Vector3d;

class Material
{
public:
    Material();
    Material(const Vector3d &, const Vector3d &, const float);

    Vector3d& getAmbient();
    Vector3d& getDiffuse();
    float getSpecular();

    Material& operator=(const Material&);
    Material& operator=(Material&);

private:
        Vector3d _diffuse;
        Vector3d _ambient; // в теории тут должен быть двумерный вектор
        float _specular;
};

}

#endif // MATERIAL_H
