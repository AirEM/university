#ifndef CAMERA_H
#define CAMERA_H

#include "../Geometry/vector3d.h"

namespace camera {

using geometry::Vector3d;

const float _base_x = 0;
const float _base_y = 5;
const float _base_z = 10;
const float _base_x_angle = 0;
const float _base_y_angle = 0;

class Camera
{
public:
    Camera();

    Vector3d getPosition() const;
    float getAngleX() const;
    float getAngleY() const;

    void moveCamera(float, float, float);
    void rotateCamera(float, float);

private:
    Vector3d _camera_position;

    float _x_angle;
    float _y_angle;
};

}

#endif // CAMERA_H
