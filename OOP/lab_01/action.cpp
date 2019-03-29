#include "action.h"


int action(command c, union u_data &data)
{
    int err = 0;

    static Model model = {nullptr, 0};

    switch(c)
    {
    case DRAW:
        err = draw(model, data.d_data);
        break;
    case CLEAN:
        err = clean(model, data.d_data);
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
    case ROTATE: std::cout << "ROTATE" << std::endl;  break;

    }

    return err;
}

int draw(const Model &model, const struct draw_data *d_data)
{
    double dist = 500.0;
    double sx_begin, sy_begin, sx_end, sy_end;

    for (int i = 0; i < model.count; i++)
    {
        sx_begin = model.lines[i].x_begin * dist / (model.lines[i].z_begin + dist);
        sy_begin = model.lines[i].y_begin * dist / (model.lines[i].z_begin + dist);

        sx_end = model.lines[i].x_end * dist / (model.lines[i].z_end + dist);
        sy_end = model.lines[i].y_end * dist / (model.lines[i].z_end + dist);

        d_data->painter->drawLine(QLineF(sx_begin, -sy_begin, sx_end, -sy_end));
    }

    return 0;
}

int clean(Model &model, const struct draw_data *data)
{
    delete []model.lines;
    model.lines = nullptr;

    model.count = 0;

    return 0;
}

int load(Model &model, const struct load_data *l_data)
{
    delete []model.lines;
    model.lines = nullptr;
    model.count = 0;

    float x_b, y_b, z_b, x_e, y_e, z_e;

    std::ifstream fin(l_data->filename);

    // проверка на откуртие файла и возвратошибки

    fin >> model.count;

    model.lines = new Line[model.count];

    for (int i = 0; i < model.count; i++)
    {
        fin >> x_b >> y_b >> z_b >> x_e >> y_e >> z_e;

        model.lines[i].x_begin = static_cast<double>(x_b);
        model.lines[i].y_begin = static_cast<double>(y_b);
        model.lines[i].z_begin = static_cast<double>(z_b);
        model.lines[i].x_end = static_cast<double>(x_e);
        model.lines[i].y_end = static_cast<double>(y_e);
        model.lines[i].z_end = static_cast<double>(z_e);
    }

    return 0;
}

int save(Model &model, const struct save_data *s_data)
{
    std::ofstream fout(s_data->filename);

    // проверка на откуртие файла и возвратошибки

    fout << model.count << std::endl;

    for (int i = 0; i < model.count; i++)
    {
        fout <<
        model.lines[i].x_begin << " " <<
        model.lines[i].y_begin << " " <<
        model.lines[i].z_begin << " " <<
        model.lines[i].x_end << " " <<
        model.lines[i].y_end << " " <<
        model.lines[i].z_end << " " <<
        std::endl;
    }

    return 0;
}

int move(Model &model, const struct move_data *m_data)
{
    for (int i = 0; i < model.count; i++)
    {
        model.lines[i].x_begin += m_data->dx;
        model.lines[i].y_begin += m_data->dy;
        model.lines[i].z_begin += m_data->dz;

        model.lines[i].x_end += m_data->dx;
        model.lines[i].y_end += m_data->dy;
        model.lines[i].z_end += m_data->dz;
    }

    return 0;
}

int scale(Model &model, const struct scale_data *sc_data)
{
    for (int i = 0; i < model.count; i++)
    {
        model.lines[i].x_begin *= sc_data->kx;
        model.lines[i].y_begin *= sc_data->ky;
        model.lines[i].z_begin *= sc_data->kz;

        model.lines[i].x_end *= sc_data->kx;
        model.lines[i].y_end *= sc_data->ky;
        model.lines[i].z_end *= sc_data->kz;
    }

    return 0;
}

int rotate(Model &model, const struct rotate_data *r_data)
{
    double fix = r_data->fix * PI / 180,
           fiy = r_data->fiy * PI / 180,
           fiz = r_data->fiz * PI / 180;

    double x, y, z;

    for (int i = 0; i < model.count; i++)
    {

        // rotate begin point on x line

        x = model.lines[i].x_begin;
        y = model.lines[i].y_begin * cos(fix) - model.lines[i].z_begin * sin(fix);
        z = model.lines[i].y_begin * sin(fix) + model.lines[i].z_begin * cos(fix);

        model.lines[i].x_begin = x;
        model.lines[i].x_begin = y;
        model.lines[i].x_begin = z;

        // rotate begin point on y line

        x = model.lines[i].x_begin * cos(fiy) + model.lines[i].z_begin * sin(fiy);
        y = model.lines[i].y_begin;
        z = -model.lines[i].x_begin * sin(fiy) + model.lines[i].z_begin * cos(fiy);

        model.lines[i].x_begin = x;
        model.lines[i].x_begin = y;
        model.lines[i].x_begin = z;

        // rotate begin point on z line

        x = model.lines[i].x_begin * cos(fiz) - model.lines[i].y_begin * sin(fiz);
        y = model.lines[i].x_begin * sin(fiz) + model.lines[i].y_begin * cos(fiz);
        z = model.lines[i].z_begin;

        model.lines[i].x_begin = x;
        model.lines[i].x_begin = y;
        model.lines[i].x_begin = z;


        //model.lines[i].x_end *= sc_data->kx;
        //model.lines[i].y_end *= sc_data->ky;
        //model.lines[i].z_end *= sc_data->kz;
    }
}
