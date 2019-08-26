#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <limits>
#include <algorithm>

#include "Material/material.h"

namespace object {

using object::Material;
using geometry::Vector3d;

class BaseObject
{
public:
    BaseObject() = default;
    virtual ~BaseObject() = default;

    virtual Material getMaterial() const = 0;
    virtual Vector3d getNormal(const Vector3d&) = 0;

    virtual bool ray_intersect(const Vector3d &, const Vector3d &, float &) const = 0;

protected:
    Material _material;
};

}

#endif // BASEOBJECT_H