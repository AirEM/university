#include "renderarea.h"

MainLabel::MainLabel(QWidget *parent) : QLabel (parent), pixmap(781, 638)
{
    pixmap.fill();
}


void MainLabel::draw()
{
    pixmap.fill();

    QPainter painter(&pixmap);

    painter.translate(QPoint(this->width() / 2, this->height() / 2));

    struct draw_data d_data;
    d_data.painter = &painter;

    union u_data data;
    data.d_data = &d_data;

    action(DRAW, data);

    this->update();
}

void MainLabel::clean()
{   
    union u_data data;

    action(CLEAN, data);

    pixmap.fill();

    this->update();
}


void MainLabel::resizeEvent(QResizeEvent *event)
{
    pixmap = pixmap.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
    pixmap.fill();
    draw();
    this->update();
}

void MainLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0), pixmap);
}
