#ifndef ACTION_H
#define ACTION_H

#include <iostream>

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

enum command {DRAW = 0, CLEAN = 1, LOAD = 2, SAVE = 3, MOVE = 4, SCALE = 5, ROTATE = 6};

error action(command, const union u_data &);

error draw(const Model &, const struct draw_data *);

error clean(Model &);

error load(Model &, const struct load_data *);

error save(const Model &, const struct save_data *);

error move(Model &, const struct move_data *);

error scale(Model &, const struct scale_data *);

error rotate(Model &, const struct rotate_data *);

#endif // ACTION_H
