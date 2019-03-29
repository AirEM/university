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
    case ROTATE:
        err = rotate(model, data.r_data);
        break;

    }

    return err;
}

int draw(const Model &model, const struct draw_data *d_data)
{
    double dist = 500.0;
    double sx_begin, sy_begin, sx_end, sy_end;

    for (int i = 0; i < model.count; i++)
    {
        sx_begin = model.lines[i].begin.x * dist / (model.lines[i].begin.z + dist);
        sy_begin = model.lines[i].begin.y * dist / (model.lines[i].begin.z + dist);

        sx_end = model.lines[i].end.x * dist / (model.lines[i].end.z + dist);
        sy_end = model.lines[i].end.y * dist / (model.lines[i].end.z + dist);

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

        model.lines[i].begin.x = static_cast<double>(x_b);
        model.lines[i].begin.y = static_cast<double>(y_b);
        model.lines[i].begin.z = static_cast<double>(z_b);
        model.lines[i].end.x = static_cast<double>(x_e);
        model.lines[i].end.y = static_cast<double>(y_e);
        model.lines[i].end.z = static_cast<double>(z_e);
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
//        fout <<
//        model.lines[i].x_begin << " " <<
//        model.lines[i].y_begin << " " <<
//        model.lines[i].z_begin << " " <<
//        model.lines[i].x_end << " " <<
//        model.lines[i].y_end << " " <<
//        model.lines[i].z_end << " " <<
//        std::endl;
    }

    return 0;
}

int move(Model &model, const struct move_data *m_data)
{
    for (int i = 0; i < model.count; i++)
    {
        model.lines[i].begin.x += m_data->dx;
        model.lines[i].begin.y += m_data->dy;
        model.lines[i].begin.z += m_data->dz;

        model.lines[i].end.x += m_data->dx;
        model.lines[i].end.y += m_data->dy;
        model.lines[i].end.z += m_data->dz;
    }

    return 0;
}

int scale(Model &model, const struct scale_data *sc_data)
{
    for (int i = 0; i < model.count; i++)
    {
        model.lines[i].begin.x *= sc_data->kx;
        model.lines[i].begin.y *= sc_data->ky;
        model.lines[i].begin.z *= sc_data->kz;

        model.lines[i].end.x *= sc_data->kx;
        model.lines[i].end.y *= sc_data->ky;
        model.lines[i].end.z *= sc_data->kz;
    }

    return 0;
}

int rotate(Model &model, const struct rotate_data *r_data)
{
    double fix = r_data->fix * PI / 180,
           fiy = r_data->fiy * PI / 180,
           fiz = r_data->fiz * PI / 180;

    for (int i = 0; i < model.count; i++)
    {
        rotate_point(model.lines[i].begin, fix, fiy, fiz);

        rotate_point(model.lines[i].end, fix, fiy, fiz);
    }

}

void rotate_point(Point &point, double fix, double fiy, double fiz)
{
    double x, y, z;

    // rotate begin point on x line

    x = point.x;
    y = point.y * cos(fix) - point.z * sin(fix);
    z = point.y * sin(fix) + point.z * cos(fix);

    point.x = x;
    point.y = y;
    point.z = z;

    // rotate begin point on y line

    x = point.x * cos(fiy) + point.z * sin(fiy);
    y = point.y;
    z = -point.x * sin(fiy) + point.z * cos(fiy);

    point.x = x;
    point.y = y;
    point.z = z;

    // rotate begin point on z line

    x = point.x * cos(fiz) - point.y * sin(fiz);
    y = point.x * sin(fiz) + point.y * cos(fiz);
    z = point.z;

    point.x = x;
    point.y = y;
    point.z = z;
}
