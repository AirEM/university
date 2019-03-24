#ifndef MODEL_H
#define MODEL_H

typedef struct model Model;
typedef struct line Line;

struct model
{
    Line *lines;
    int count;
};

struct line
{
    double x_begin, y_begin, z_begin;
    double x_end, y_end, z_end;
};

#endif // MODEL_H
