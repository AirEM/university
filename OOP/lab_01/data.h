#ifndef DATA_H
#define DATA_H

#include <QPainter>

#define PI 3.14159265

struct draw_data
{
    QPainter *painter;
};

struct load_data
{
    char *filename;
};

struct save_data
{
    char *filename;
};

struct move_data
{
    double dx, dy, dz;
};

struct scale_data
{
    double kx, ky, kz;
};

struct rotate_data
{
    double fix, fiy, fiz;
};




#endif // DATA_H