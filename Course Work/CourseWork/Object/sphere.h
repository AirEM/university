#ifndef SPHERE_H
#define SPHERE_H

#include "baseobject.h"

namespace object {

class Sphere : public BaseObject
{
public:
    Sphere(int, Vector3d, size_t, Material);

    Vector3d getNormal(const Vector3d&) const override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) override;

private:
    Vector3d _center;
    size_t _radius;
    size_t _radius2;
};

}

#endif // SPHERE_H
