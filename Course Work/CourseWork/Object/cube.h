#ifndef CUBE_H
#define CUBE_H

#include "baseobject.h"

namespace object {

class Cube : public BaseObject
{
public:
    Cube(Vector3d&, Vector3d&, Material&);

    Vector3d getCenter();
    Material getMaterial();
    Vector3d getNormal(const Vector3d&);

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const;

private:
    Vector3d min_point;
    Vector3d max_point;

    Vector3d normal[6];

    bool test(const Vector3d&, Vector3d&, Vector3d&) const;

    Vector3d getM(int);

};

}

#endif // CUBE_H
