#include "action.h"


error action(command c, const union u_data &data)
{
    error err = SUCCESS;

    static Model model = {nullptr, 0};

    switch(c)
    {
    case DRAW:
        err = draw(model, data.d_data);
        break;
    case CLEAN:
        err = clean(model);
        break;
    case LOAD:
        err = load(model, data.l_data);
        break;
    case SAVE:
        err = save(model, data.s_data);
        break;
    case MOVE:
        err = move(model, data.m_data);
        break;
    case SCALE:
        err = scale(model, data.sc_data);
        break;
    case ROTATE:
        err = rotate(model, data.r_data);
        break;

    }

    return err;
}

error draw(const Model &model, const struct draw_data *d_data)
{
    error err = SUCCESS;

    double dist = 500.0;
    double sx_begin, sy_begin, sx_end, sy_end;

    if (model.count < 1 || model.lines == nullptr)
        err = ERR_MODEL;
    else
    {
        for (int i = 0; i < model.count; i++)
        {
            sx_begin = model.lines[i].begin.x * dist / (model.lines[i].begin.z + dist);
            sy_begin = model.lines[i].begin.y * dist / (model.lines[i].begin.z + dist);

            sx_end = model.lines[i].end.x * dist / (model.lines[i].end.z + dist);
            sy_end = model.lines[i].end.y * dist / (model.lines[i].end.z + dist);

            d_data->painter->drawLine(QLineF(sx_begin, -sy_begin, sx_end, -sy_end));
        }
    }

    return err;
}

error clean(Model &model)
{
    model_clean(model);

    return SUCCESS;
}

error load(Model &model, const struct load_data *l_data)
{
    error err = SUCCESS;
    Model copy_model = {nullptr, 0};

    FILE *f;

    f = fopen(l_data->filename, "r");

    if (f == nullptr)
        err = ERR_FILE;
    else
    {
        model_copy(model, copy_model);
        model_clean(model);

        err = model_load(f, model);

        if (err != SUCCESS)
            model_copy(copy_model, model);

        model_clean(copy_model);

        fclose(f);
    }

    return err;
}

error save(const Model &model, const struct save_data *s_data)
{
    error err = SUCCESS;

    FILE *f;

    f = fopen(s_data->filename, "w");

    if (f == nullptr)
        err = ERR_FILE;
    else
    {
        err = model_save(f, model);

        fclose(f);
    }

    return err;
}

error move(Model &model, const struct move_data *m_data)
{
    error err = SUCCESS;

    if (model.count < 1 || model.lines == nullptr)
        err = ERR_MODEL;
    else
        model_move(model, m_data->dx, m_data->dy, m_data->dz);

    return err;
}

error scale(Model &model, const struct scale_data *sc_data)
{
    error err = SUCCESS;

    if (model.count < 1 || model.lines == nullptr)
        err = ERR_MODEL;
    else
        model_scale(model, sc_data->kx, sc_data->ky, sc_data->kz);

    return err;
}

error rotate(Model &model, const struct rotate_data *r_data)
{
    error err = SUCCESS;

    double fi_x = r_data->fi_x * PI / 180,
           fi_y = r_data->fi_y * PI / 180,
           fi_z = r_data->fi_z * PI / 180;

    if (model.count < 1 || model.lines == nullptr)
        err = ERR_MODEL;
    else
        model_rotate(model, fi_x, fi_y, fi_z);

    return err;
}

