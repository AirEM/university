#ifndef POINT_H
#define POINT_H

#include <cmath>

typedef struct point Point;

struct point
{
    double x, y, z;
};

void point_move(Point &, double, double, double);

void point_scale(Point &, double, double, double);

void point_rotate(Point &, double, double, double);

void point_copy(const Point &, Point &);

#endif // POINT_H
