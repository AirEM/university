#include "cone.h"

namespace object {

Cone::Cone(Vector3d& c, int h, int r, Material& m) : _centre(c), _height(h), _rad(r)
{
    this->_material = m;

    _a = _rad;
    _c = _rad;
    _b = _height;
}

Vector3d Cone::getCenter()
{
    return Vector3d();
}

Material Cone::getMaterial()
{
    return _material;
}

Vector3d Cone::getNormal(const Vector3d& hit)
{

    Vector3d A = hit;
    Vector3d C(_centre.getX(), _centre.getY() + _height, _centre.getZ());


    float k = ((A.getX() - _centre.getX())*C.getX() + (A.getZ() - _centre.getZ())*C.getZ()) / C.getY() + A.getY();

    Vector3d AB(A.getX() - _centre.getX(), A.getY() - k, A.getZ() - _centre.getZ());

    AB.normalize();

    return AB;
}

bool Cone::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0) const
{

    float t_near = std::numeric_limits<float>::min(),
    t_far = std::numeric_limits<float>::max();


    float alfa  = _b*_b * _c*_c;
    float betta = _a*_a * _c*_c;
    float gamma = _a*_a * _b*_b;

    float Dx = orig.getX() - _centre.getX();
    float Dy = orig.getY() - _centre.getY();
    float Dz = orig.getZ() - _centre.getZ();

    float A = alfa*dir.getX()*dir.getX() - betta*dir.getY()*dir.getY() + gamma*dir.getZ()*dir.getZ();
    float B = 2 * (alfa*dir.getX()*Dx - betta*dir.getY()*Dy + gamma*dir.getZ()*Dz);
    float C = alfa*Dx*Dx - betta*Dy*Dy + gamma*Dz*Dz;

    float disk = B*B - 4*A*C;

    if (disk < 0)
        return false;


    disk = sqrtf(disk);

    float t1, t2;

    t1 = (-B + disk) / (2*A);
    t2 = (-B - disk) / (2*A);


    if (t1 > t2)
    {
        // std::swap(t1, t2);
        float tmp = t1;
        t1 = t2;
        t2 = tmp;

    }

    if (t1 > t_near)
    {
        t_near = t1;
    }

    if (t2 < t_far)
        t_far = t2;

    if (t_near > t_far)
        return false;

    if (t_far < 0.0f)
        return false;


    t0 = t_near;

    Vector3d hit = orig + (dir * t0);
    if (hit.getY() < _centre.getY() - _height || hit.getY() > _centre.getY())
    {
        t0 = t_far;
        hit = orig + (dir * t0);
    }

    if (hit.getY() < _centre.getY() - _height || hit.getY() > _centre.getY())
        return false;

    if (hit.getX() < _centre.getX() - _a ||
            hit.getX() > _centre.getX() + _a ||
            hit.getZ() < _centre.getZ() - _c ||
            hit.getZ() > _centre.getZ() + _c)
        return false;

    return (t_near <= t_far && t_far >=0);
}

}
