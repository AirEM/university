#ifndef CAMERA_H
#define CAMERA_H

#include "../Geometry/vector3d.h"

namespace camera {

using geometry::Vector3d;

const float _base_x = 0;
const float _base_y = 0;
const float _base_z = 0;

class Camera
{
public:
    Camera();

    Vector3d getCoordinates() const;

private:
    Vector3d _camera_coordinates;
};

}

#endif // CAMERA_H
