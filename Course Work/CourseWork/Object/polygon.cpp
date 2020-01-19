#include "polygon.h"

namespace object {


Polygon::Polygon(int id)
{
    this->_id = id;


}

Vector3d Polygon::getNormal(const Vector3d& hit) const
{
    return Vector3d(0,1,0);
}

bool Polygon::ray_intersect(const Vector3d &orig, const Vector3d &dir, float &t0)
{
//    float scene_dist = std::numeric_limits<float>::max();

//    if ( fabs(static_cast<double>(dir.getY())) > 1e-3)
//    {
//        float d = -(orig.getY()) / dir.getY();

//        Vector3d pt = orig + dir*d;

//        if (d > 0 && fabs(pt.getX()) < 10 && pt.getZ() < 0 && pt.getZ() > -20)
//        {
//            scene_dist = d;

////            this->_material = (int(0.5f * pt.getX() + 1000) + int(0.5f * pt.getZ()) ) & 1
////                    ?
////                        Material(Vector3d(0.3f, 0.3f, 0.3f), Vector3d(0.3f, 0.3f, 0.3f) , 0)
////                      :
////                        Vector3d(0.3f, 0.2f, 0.1f);
//            setMat(true);
//        }
//    }

    float checkerboard_dist = std::numeric_limits<float>::max();

    if (fabs(static_cast<double>(dir.getY())) > 1e-3)
    {
        float d = -(orig.getY()) / dir.getY(); // the checkerboard plane has equation y = -4

        Vector3d pt = orig + dir*d;

        if (d > 0 && fabs(pt.getX()) < 10 && pt.getZ() < 0 && pt.getZ() > -20)
        {
            checkerboard_dist = d;

            Vector3d hit = pt;

            if (orig.getY() >= 0)
                _normal = Vector3d(0,1,0);
            else
                _normal = Vector3d(0,-1,0);

            _material.getDiffuse() = (int(0.5f * hit.getX() + 1000) + int(0.5f * hit.getZ())) & 1 ?
                        Vector3d(0.3f, 0.3f, 0.3f)  :
                        Vector3d(0.3f, 0.2f, 0.1f);
        }
    }

    t0 = checkerboard_dist;

    return checkerboard_dist < 1000;
}




}

