#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "Material/material.h"

namespace object {

using object::Material;
using geometry::Vector3d;

class BaseObject
{
public:
    BaseObject() = default;
    virtual ~BaseObject() = default;

    virtual Vector3d getCenter() = 0;
    virtual Material getMaterial() = 0;

    virtual bool ray_intersect(const Vector3d &, const Vector3d &, float &) const = 0;

protected:
    Material _material;
};

}

#endif // BASEOBJECT_H
