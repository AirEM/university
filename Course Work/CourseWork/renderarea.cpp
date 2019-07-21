#include "renderarea.h"

MainLabel::MainLabel(QWidget *parent) : QLabel (parent), _pixmap(781, 638)
{
    _pixmap.fill();
}


QPixmap* MainLabel::getPixmap()
{
    return &_pixmap;
}


void MainLabel::draw()
{
    _pixmap.fill();

    QPainter painter(&_pixmap);

    painter.translate(QPoint(this->width() / 2, this->height() / 2));

//    struct draw_data d_data;
//    d_data.painter = &painter;

//    union u_data data;
//    data.d_data = &d_data;

//    action(DRAW, data);

    this->update();
}

void MainLabel::clean()
{   
//    union u_data data;

//    action(CLEAN, data);

    _pixmap.fill();

    this->update();
}


void MainLabel::resizeEvent(QResizeEvent *event)
{
    _pixmap = _pixmap.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio);
    _pixmap.fill();
    draw();
    this->update();
}

void MainLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0), _pixmap);
}
