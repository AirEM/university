#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct line Line;

struct line
{
    Point begin;
    Point end;
};

void line_move(Line &, double, double, double);

void line_scale(Line &, double, double, double);

void line_rotate(Line &, double, double, double);

void line_copy(const Line &, Line);

#endif // LINE_H
