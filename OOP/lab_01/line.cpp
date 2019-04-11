#include "line.h"

void line_move(Line& line, double dx, double dy, double dz)
{
    point_move(line.begin, dx, dy, dz);

    point_move(line.end, dx, dy, dz);
}

void line_scale(Line& line, double kx, double ky, double kz)
{
    point_scale(line.begin, kx, ky, kz);

    point_scale(line.end, kx, ky, kz);
}

void line_rotate(Line& line, double fi_x, double fi_y, double fi_z)
{
    point_rotate(line.begin, fi_x, fi_y, fi_z);

    point_rotate(line.end, fi_x, fi_y, fi_z);
}

void line_copy(const Line& line, Line copy_line)
{
    point_copy(line.begin, copy_line.begin);

    point_copy(line.end, copy_line.end);
}
