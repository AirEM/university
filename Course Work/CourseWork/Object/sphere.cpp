#include "sphere.h"

namespace object {

Sphere::Sphere(int id, Vector3d centre, size_t radius, Material m) : _center(centre), _radius(radius)
{
    this->_id = id;
    this->_material = m;
    this->_radius2 = _radius * _radius;
}


Vector3d Sphere::getNormal(const Vector3d& hit) const
{
    Vector3d N = (hit - this->_center).normalize();

    return N;
}


bool Sphere::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0)
{

    // Луч, напрвленный от камеры к центру сферы
    Vector3d L = this->_center - orig;

    // Блидайшая  к центру сферы точка на луче
    float tca = L * dir;

    // Разность между квадратами двух лучей
    float d2 = L*L - tca*tca;

    // Если их разность больше квадрата радиуса
    // то данный луч в напрвлении dir сферу не пересекает
    if (d2 > this->_radius2)
        return false;

    float thc = sqrtf(this->_radius2 - d2);

    t0 = tca - thc;

    float t1 = tca + thc;

    if (t0 < 0)
        t0 = t1;

    if (t0 < 0)
        return false;

    return true;
}


}
