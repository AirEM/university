#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string.h>
#include <cmath>

namespace geometry {

class Vector3d
{
public:
    Vector3d();
    Vector3d(float, float, float);

    float get(int) const;

    float getX() const;
    float getY() const;
    float getZ() const;

    Vector3d& normalize();
    float length() const;

    Vector3d mult(const float) const;
    float mult(const Vector3d&) const;

    Vector3d& operator=(const Vector3d&);
    Vector3d& operator=(Vector3d&);

    Vector3d operator-(const Vector3d&) const;

    Vector3d operator+(const Vector3d&) const;

    float operator*(const Vector3d&) const;
    Vector3d operator*(const float) const;



private:
    float _x;
    float _y;
    float _z;

};

}

#endif // VECTOR3D_H
