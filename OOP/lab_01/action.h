#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <fstream>

#include "data.h"
#include "model.h"

union u_data
{
    struct draw_data *d_data;
    struct load_data *l_data;
};

enum command {DRAW, LOAD, SAVE, MOVE, SCALE, ROTATE};

int action(command, union u_data &);

int draw(const Model &, const struct draw_data *);

int load(Model &, const struct load_data *);

#endif // ACTION_H
