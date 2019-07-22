#include "point.h"

void point_move(Point& point, double dx, double dy, double dz)
{
    point.x += dx;
    point.y += dy;
    point.z += dz;
}

void point_scale(Point& point, double kx, double ky, double kz)
{
    point.x *= kx;
    point.y *= ky;
    point.z *= kz;
}

void point_rotate(Point& point, double fi_x, double fi_y, double fi_z)
{
    double x, y, z;

    // rotate point around x line

    x = point.x;
    y = point.y * cos(fi_x) - point.z * sin(fi_x);
    z = point.y * sin(fi_x) + point.z * cos(fi_x);

    point.x = x;
    point.y = y;
    point.z = z;

    // rotate point around y line

    x = point.x * cos(fi_y) + point.z * sin(fi_y);
    y = point.y;
    z = -point.x * sin(fi_y) + point.z * cos(fi_y);

    point.x = x;
    point.y = y;
    point.z = z;

    // rotate point around z line

    x = point.x * cos(fi_z) - point.y * sin(fi_z);
    y = point.x * sin(fi_z) + point.y * cos(fi_z);
    z = point.z;

    point.x = x;
    point.y = y;
    point.z = z;
}

void point_copy(const Point& point, Point& copy_point)
{
    copy_point.x = point.x;
    copy_point.y = point.y;
    copy_point.z = point.z;
}
