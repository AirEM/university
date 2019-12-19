#ifndef POLYGON_H
#define POLYGON_H

#include "baseobject.h"


namespace object {


class Polygon : public BaseObject
{
public:
    Polygon(int);

    Vector3d getNormal(const Vector3d&) const override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) override;

private:
    Vector3d _normal;


};

}
#endif // POLYGON_H
