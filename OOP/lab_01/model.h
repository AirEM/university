#ifndef MODEL_H
#define MODEL_H

typedef struct point Point;
typedef struct line Line;
typedef struct model Model;


struct point
{
    double x, y, z;
};

struct line
{
    Point begin;
    Point end;
};


struct model
{
    Line *lines;
    int count;
};

#endif // MODEL_H
