#ifndef SPHERE_H
#define SPHERE_H

#include "baseobject.h"

namespace object {

class Sphere : public BaseObject
{
public:
    Sphere(int, Vector3d, size_t, Material);

    Material getMaterial() const override;
    Vector3d getNormal(const Vector3d&) override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const override;

private:
    Vector3d _centre;
    size_t _radius;
};

}

#endif // SPHERE_H
