#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include <fstream>
#include <cmath>

#include "data.h"
#include "model.h"

union u_data
{
    struct draw_data *d_data;
    struct load_data *l_data;
    struct save_data *s_data;
    struct move_data *m_data;
    struct scale_data *sc_data;
    struct rotate_data *r_data;
};

enum command {DRAW, CLEAN, LOAD, SAVE, MOVE, SCALE, ROTATE};

int action(command, union u_data &);

int draw(const Model &, const struct draw_data *);

int clean(Model &, const struct draw_data *);

int load(Model &, const struct load_data *);

int save(Model &, const struct save_data *);

int move(Model &, const struct move_data *);

int scale(Model &, const struct scale_data *);

int rotate(Model &, const struct rotate_data *);

void rotate_point(Point &, double, double, double);

#endif // ACTION_H
