#include "sphere.h"

namespace object {

Sphere::Sphere(Vector3d centre, size_t radius, Material m) : _centre(centre), _radius(radius)
{
    this->_material = m;
}


Vector3d Sphere::getCenter()
{
    return _centre;
}

Material Sphere::getMaterial()
{
    return _material;
}


bool Sphere::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0) const
{
        Vector3d L = this->_centre - orig;

        float tca = L * dir;

        float d2 = L*L - tca*tca;

        if (d2 > this->_radius * this->_radius)
            return false;

        float thc = sqrtf(this->_radius * this->_radius - d2);

        t0 = tca - thc;

        float t1 = tca + thc;

        if (t0 < 0)
            t0 = t1;

        if (t0 < 0)
            return false;

        return true;
}


}
