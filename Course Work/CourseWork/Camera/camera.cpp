#include "camera.h"

namespace camera
{

Camera::Camera() : _camera_position(_base_x, _base_y, _base_z),
    _x_angle(_base_x_angle), _y_angle(_base_y_angle) {}

Vector3d Camera::getPosition() const
{
    return _camera_position;
}

float Camera::getAngleX() const
{
    return _x_angle;
}

float Camera::getAngleY() const
{
    return _y_angle;
}


void Camera::moveCamera(float x, float y, float z)
{
    Vector3d delta(x, y, z);
    this->_camera_position = this->_camera_position + delta;
}

void Camera::rotateCamera(float angle_x, float angle_y)
{
    this->_x_angle += angle_x;
    this->_y_angle += angle_y;
}

}
