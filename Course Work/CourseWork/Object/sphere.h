#ifndef SPHERE_H
#define SPHERE_H

#include "baseobject.h"

namespace object {

class Sphere : public BaseObject
{
public:
    Sphere(Vector3d, size_t, Material);

    Vector3d getCenter() override;
    Material getMaterial() override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const override;

private:
    Vector3d _centre;
    size_t _radius;
};

}

#endif // SPHERE_H
