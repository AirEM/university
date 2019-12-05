#ifndef CONE_H
#define CONE_H

#include "baseobject.h"

namespace object {

class Cone : public BaseObject
{
public:
    Cone(int, Vector3d& , int, int, Material&);

    Material getMaterial() const override;
    Vector3d getNormal(const Vector3d&) override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const override;

private:
    Vector3d _centre;
    int _height;
    int _radius;

    // Коэффициенты для вычисления пересечения луча с фигурой
    // (Ускоряют вычисления)
    float _alfa;
    float _betta;
    float _gamma;


};

}

#endif // CONE_H
