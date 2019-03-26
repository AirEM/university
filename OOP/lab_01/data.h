#ifndef DATA_H
#define DATA_H

#include <QPainter>

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

#endif // DATA_H
