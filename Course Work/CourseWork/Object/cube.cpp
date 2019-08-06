#include "cube.h"

namespace object {

Cube::Cube(Vector3d& min, Vector3d& max, Material& m)
{
    min_point = min;
    max_point = max;
    this->_material = m;

    normal[0] = Vector3d(0, 0, 1);
    normal[1] = Vector3d(0, 0, -1);
    normal[2] = Vector3d(-1, 0, 0);
    normal[3] = Vector3d(1, 0, 0);
    normal[4] = Vector3d(0, 1, 0);
    normal[5] = Vector3d(0, -1, 0);
}

Vector3d Cube::getCenter()
{
    return Vector3d();
}

Material Cube::getMaterial()
{
    return _material;
}

Vector3d Cube::getNormal(const Vector3d& hit)
{
    Vector3d N;

    Vector3d M;

    for (int i = 0; i < 6; i++)
    {

        M = getM(i);

        if (test(hit, this->normal[i], M))
        {
            N = this->normal[i];
            break;
        }
    }

    N.normalize();

    return N;
}


Vector3d Cube::getM(int i)
{
    if (i == 5)
        return min_point;

    if (i == 4)
        return max_point;

    if (i % 2 == 0)
        return min_point;
    else
        return max_point;
}



bool Cube::test(const Vector3d& hit, Vector3d& N, Vector3d& M) const
{
    float A = N.getX();
    float B = N.getY();
    float C = N.getZ();

    float x0 = M.getX();
    float y0 = M.getY();
    float z0 = M.getZ();

    float x = hit.getX();
    float y = hit.getY();
    float z = hit.getZ();

    bool res = false;

    float t = A*(x-x0) + B*(y-y0) + C*(z-z0);

    if ( static_cast<float>(fabs(static_cast<double>(t))) < 1e-3f)
        res = true;

    return res;
}


bool Cube::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0) const
{
    // check whether initial point is inside the parallelepiped
//    if ( ray.start[0] >= brick.min_point[0] && ray.start[0] <= brick.max_point[0] &&
//         ray.start[1] >= brick.min_point[1] && ray.start[1] <= brick.max_point[1] &&
//         ray.start[2] >= brick.min_point[2] && ray.start[2] <= brick.max_point[2] ) {
//        return true;
//    }

    // ray parameter
    float t_near = std::numeric_limits<float>::min(),
    t_far = std::numeric_limits<float>::max();
    float t1 = 0, t2 = 0;

    // directions loop
    for (int i = 0; i < 3; i++)
    {
        if ( fabs(static_cast<double>(dir.get(i))) >= std::numeric_limits<double>::epsilon() )
        {
            t1 = (min_point.get(i) - orig.get(i)) / dir.get(i);
            t2 = (max_point.get(i) - orig.get(i)) / dir.get(i);

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

        } // if
        else
        {
            if ( orig.get(i) < min_point.get(i) || orig.get(i) > max_point.get(i) )
                return false;
        }
    } // for

    t0 = t_near;

    return (t_near <= t_far && t_far >=0);

/*
    float lo = dir.getX()*(min_point.getX() - orig.getX());

    float hi = dir.getX()*(max_point.getX() - orig.getX());

    float tmin  = std::min(lo, hi);

    float tmax = std::max(lo, hi);



    float lo1 = dir.getY() * (min_point.getY() - orig.getY());

    float hi1 = dir.getY() * (max_point.getY() - orig.getY());

    tmin = std::max(tmin, std::min(lo1, hi1));

    tmax = std::min(tmax, std::max(lo1, hi1));



    float lo2 = dir.getZ() * (min_point.getZ() - orig.getZ());

    float hi2 = dir.getZ() * (max_point.getZ() - orig.getZ());

    tmin = std::max(tmin, std::min(lo2, hi2));

    tmax = std::min(tmax, std::max(lo2, hi2));


    t0 = tmin;


    return (tmin <= tmax) && (tmax > 0.f);
    */

}

}
