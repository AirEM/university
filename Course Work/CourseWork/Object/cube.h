#ifndef CUBE_H
#define CUBE_H

#include "baseobject.h"

namespace object {

class Cube : public BaseObject
{
public:
    Cube(int, Vector3d&, Vector3d&, Material&);

    Vector3d getNormal(const Vector3d&) const override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const override;

private:
    Vector3d _min_point;
    Vector3d _max_point;

    Vector3d _normal[6];

    bool dot(const Vector3d&, const Vector3d&, Vector3d&) const;

    Vector3d getM(int) const;

};

}

#endif // CUBE_H
