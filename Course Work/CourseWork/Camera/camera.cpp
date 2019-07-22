#include "camera.h"

namespace camera
{

Camera::Camera() : _camera_coordinates(_base_x, _base_y, _base_z) {}

Vector3d Camera::getCoordinates() const
{
    return _camera_coordinates;
}

}
