#ifndef DATA_H
#define DATA_H

#include <QPainter>

struct load_data
{
    char *filename;
};

struct draw_data
{
    QPainter *painter;
};

#endif // DATA_H
