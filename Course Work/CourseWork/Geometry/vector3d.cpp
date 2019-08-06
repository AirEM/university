#include "vector3d.h"

namespace geometry {

Vector3d::Vector3d() : _x(0), _y(0), _z(0) {}


Vector3d::Vector3d(float x, float y, float z) : _x(x), _y(y), _z(z) {}

float Vector3d::get(int ind) const
{
    float res = 0;

    switch (ind)
    {
    case 0:
        res = _x;
        break;

    case 1:
        res = _y;
        break;

    case 2:
        res = _z;
        break;

    }

    return res;
}



float Vector3d::getX() const
{
    return _x;
}

float Vector3d::getY()const
{
    return _y;
}

float Vector3d::getZ() const
{
    return _z;
}


float Vector3d::length() const
{
    return sqrtf(_x*_x + _y*_y + _z*_z);
}

Vector3d& Vector3d::normalize()
{
    float l = 1;
    float len = length();
    float inv_length = l / len;

    *this = (*this) * inv_length;

    return *this;
}


Vector3d Vector3d::mult(const float rhs) const
{
    Vector3d ret(this->getX() * rhs,
                 this->getY() * rhs,
                 this->getZ() * rhs);

    return ret;
}

float Vector3d::mult(const Vector3d& rhs) const
{
    float ret = 0.0;

    ret += this->getX() * rhs.getX();
    ret += this->getY() * rhs.getY();
    ret += this->getZ() * rhs.getZ();

    return ret;
}


Vector3d& Vector3d::operator=(const Vector3d& right)
{
    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }

    this->_x = right._x;
    this->_y = right._y;
    this->_z = right._z;

    return *this;
}

Vector3d& Vector3d::operator=(Vector3d& right)
{
    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }

    this->_x = right._x;
    this->_y = right._y;
    this->_z = right._z;

    return *this;
}


Vector3d Vector3d::operator-(const Vector3d& rhs) const
{
    Vector3d ret(this->getX() - rhs.getX(),
                 this->getY() - rhs.getY(),
                 this->getZ() - rhs.getZ());

    return ret;
}

Vector3d Vector3d::operator+(const Vector3d& rhs) const
{
    Vector3d ret(this->getX() + rhs.getX(),
                 this->getY() + rhs.getY(),
                 this->getZ() + rhs.getZ());

    return ret;
}


float Vector3d::operator*(const Vector3d& rhs) const
{
    return this->mult(rhs);
}

Vector3d Vector3d::operator*(const float rhs) const
{
    return this->mult(rhs);
}

}
