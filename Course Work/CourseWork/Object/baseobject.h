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

    virtual int getID() const { return _id; }
    virtual Material getMaterial() const {return _material; }
    virtual Vector3d getNormal(const Vector3d&) const = 0;

    virtual bool ray_intersect(const Vector3d &, const Vector3d &, float &) = 0;

protected:
    int _id;
    Material _material;
};

}

#endif // BASEOBJECT_H
