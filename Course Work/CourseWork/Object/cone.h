#ifndef CONE_H
#define CONE_H

#include "baseobject.h"

namespace object {

class Cone : public BaseObject
{
public:
    Cone(Vector3d& , int, int, Material&);

    Vector3d getCenter();
    Material getMaterial();
    Vector3d getNormal(const Vector3d&);

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const;

private:
    Vector3d _centre;
    int _height;
    int _rad;

    float _a, _b, _c;


};

}

#endif // CONE_H
