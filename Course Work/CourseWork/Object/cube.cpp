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



Material Cube::getMaterial() const
{
    return _material;
}

Vector3d Cube::getNormal(const Vector3d& hit)
{
    Vector3d N;

    Vector3d M;

    for (int i = 0; i < 6; i++)
    {

        // Точка, принадлежащая этой плоскости
        M = getM(i);

        // Скалярное произведение Нормали и вектора hit,M

        // !!! Заменить га функцию dot
        if (test(hit, this->normal[i], M))
        {
            N = this->normal[i];
            break;
        }
    }

    N.normalize();

    return N;
}


bool Cube::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0) const
{
//    // check whether initial point is inside the parallelepiped
//    if ( ray.start[0] >= brick.min_point[0] && ray.start[0] <= brick.max_point[0] &&
//         ray.start[1] >= brick.min_point[1] && ray.start[1] <= brick.max_point[1] &&
//         ray.start[2] >= brick.min_point[2] && ray.start[2] <= brick.max_point[2] ) {
//        return true;
//    }

    float t_near = std::numeric_limits<float>::min();
    float t_far = std::numeric_limits<float>::max();
    float t1, t2;


    for (int i = 0; i < 3; i++)
    {
        if ( fabs(static_cast<double>(dir.get(i))) >= std::numeric_limits<double>::epsilon() )
        {
            t1 = (min_point.get(i) - orig.get(i)) / dir.get(i);
            t2 = (max_point.get(i) - orig.get(i)) / dir.get(i);


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
        }
        else
        {
            if ( orig.get(i) < min_point.get(i) || orig.get(i) > max_point.get(i) )
                return false;
        }
    }

    t0 = t_near;

    return (t_near <= t_far && t_far >=0);
}

// Внутреннии функции

Vector3d Cube::getM(int i) const
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


}
