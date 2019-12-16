#include "cone.h"

namespace object {

Cone::Cone(int id, Vector3d& c, int h, int r, Material& m) : _centre(c), _height(h), _radius(r)
{
    this->_id = id;
    this->_material = m;

    _alfa  = _height*_height * _radius*_radius;
    _betta = _radius*_radius * _radius*_radius;
    _gamma = _radius*_radius * _height*_height;
}



Vector3d Cone::getNormal(const Vector3d& hit) const
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

    float t_near = std::numeric_limits<float>::min();
    float t_far = std::numeric_limits<float>::max();

    float Dx = orig.getX() - _centre.getX();
    float Dy = orig.getY() - _centre.getY();
    float Dz = orig.getZ() - _centre.getZ();

    // Коэффициенты квадратного уравнения
    float A = _alfa*dir.getX()*dir.getX() - _betta*dir.getY()*dir.getY() + _gamma*dir.getZ()*dir.getZ();
    float B = 2 * (_alfa*dir.getX()*Dx - _betta*dir.getY()*Dy + _gamma*dir.getZ()*Dz);
    float C = _alfa*Dx*Dx - _betta*Dy*Dy + _gamma*Dz*Dz;

    // Дискриминант
    float discriminant = B*B - 4*A*C;

    if (discriminant < 0)
        return false;

    discriminant = sqrtf(discriminant);

    float t1, t2;

    t1 = (-B + discriminant) / (2*A);
    t2 = (-B - discriminant) / (2*A);


    if (t1 > t2)
        std::swap<float>(t1, t2);

    if (t1 > t_near)
        t_near = t1;

    if (t2 < t_far)
        t_far = t2;

    if (t_near > t_far)
        return false;

    if (t_far < 0.0f)
        return false;


    t0 = t_near;


    // Ограничение конической поверхности сверху и снизу
    Vector3d hit = orig + (dir * t0);

    if (hit.getY() < _centre.getY() - _height || hit.getY() > _centre.getY())
    {
        t0 = t_far;
        hit = orig + (dir * t0);
    }

    if (hit.getY() < _centre.getY() - _height || hit.getY() > _centre.getY())
        return false;


    // Проверка попадания луча в конус
    if (hit.getX() < _centre.getX() - _radius ||
            hit.getX() > _centre.getX() + _radius ||
            hit.getZ() < _centre.getZ() - _radius ||
            hit.getZ() > _centre.getZ() + _radius)
        return false;


    return (t_near <= t_far && t_far >=0);
}

}
