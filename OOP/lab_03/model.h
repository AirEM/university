#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include "line.h"
#include "error.h"

typedef struct model Model;

struct model
{
    Line *lines;
    int count;
};

void model_move(Model &, double, double, double);

void model_scale(Model &, double, double, double);

void model_rotate(Model &, double, double, double);

void model_copy(const Model &, Model);

error model_save(FILE * , const Model &);

error model_load(FILE *, Model &);

void model_clean(Model &);

#endif // MODEL_H
