#ifndef CUBE_H
#define CUBE_H

#include "baseobject.h"

namespace object {

class Cube : public BaseObject
{
public:
    Cube(int, Vector3d&, Vector3d&, Material&);

    Material getMaterial() const override;
    Vector3d getNormal(const Vector3d&) override;

    bool ray_intersect(const Vector3d &, const Vector3d &, float &) const override;

private:
    // Vector3d _left_point;
    // int _edge_len;
    // Матрица поврота


    Vector3d min_point; // Удалить
    Vector3d max_point; // Удалить

    Vector3d normal[6];

    bool test(const Vector3d&, Vector3d&, Vector3d&) const;

    Vector3d getM(int) const;

};

}

#endif // CUBE_H
