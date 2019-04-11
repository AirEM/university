#include "model.h"

void model_move(Model& model, double dx, double dy, double dz)
{
    for (int i = 0; i < model.count; i++)
        line_move(model.lines[i], dx, dy, dz);
}

void model_scale(Model& model, double kx, double ky, double kz)
{
    for (int i = 0; i < model.count; i++)
        line_scale(model.lines[i], kx, ky, kz);
}

void model_rotate(Model& model, double fi_x, double fi_y, double fi_z)
{
    for (int i = 0; i < model.count; i++)
        line_rotate(model.lines[i], fi_x, fi_y, fi_z);
}

void model_copy(const Model& model, Model copy_model)
{
    if (model.count > 0 && model.lines != nullptr)
    {
        copy_model.count = model.count;
        copy_model.lines = new Line[copy_model.count];

        for (int i = 0; i < copy_model.count; i++)
            line_copy(model.lines[i], copy_model.lines[i]);
    }
}

error model_save(FILE *file, const Model& model)
{
    error err = SUCCESS;

    int count;

    count = fprintf(file, "%d\n", model.count);

    if (count < 0)
        err = ERR_FILE_ACTION;
    else
    {
        for (int i = 0; i < model.count; i++)
        {
            count = fprintf(file, "%lf %lf %lf %lf %lf %lf\n",
                            model.lines[i].begin.x, model.lines[i].begin.y, model.lines[i].begin.z,
                            model.lines[i].end.x, model.lines[i].end.y, model.lines[i].end.z);

            if (count < 0)
            {
                err = ERR_FILE_ACTION;
                break;
            }
        }
    }

    return err;
}

error model_load(FILE *file, Model& model)
{
    error err = SUCCESS;

    int count;
    double x_b, y_b, z_b, x_e, y_e, z_e;

    count = fscanf(file, "%d", &(model.count));

    if (count != 1 && model.count > 0)
    {
        err = ERR_FILE_ACTION;
    }
    else
    {

        model.lines = new Line[model.count];

        for (int i = 0; i < model.count; i++)
        {
            count = fscanf(file, "%lf %lf %lf %lf %lf %lf", &x_b, &y_b, &z_b, &x_e, &y_e, &z_e);


            if (count != 6)
            {
                err = ERR_FILE_ACTION;
                break;
            }
            else
            {
                model.lines[i].begin.x = x_b;
                model.lines[i].begin.y = y_b;
                model.lines[i].begin.z = z_b;
                model.lines[i].end.x = x_e;
                model.lines[i].end.y = y_e;
                model.lines[i].end.z = z_e;
            }
        }
    }

    return err;
}

void model_clean(Model &model)
{
    if (model.lines != nullptr)
        delete []model.lines;

    model.lines = nullptr;

    model.count = 0;
}
