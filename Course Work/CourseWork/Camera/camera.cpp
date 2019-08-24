#include "camera.h"

namespace camera
{

Camera::Camera() : _camera_position(_base_x, _base_y, _base_z) {}

Vector3d Camera::getPosition() const
{
    return _camera_position;
}

}
