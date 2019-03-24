#include "renderarea.h"

MainLabel::MainLabel(QWidget *parent) : QLabel (parent), pixmap(781, 638)
{
    pixmap.fill();
}


void MainLabel::draw()
{
    QPainter painter(&pixmap);

    painter.translate(QPoint(this->width() / 2, this->height() / 2));

//    painter.drawLine(0, 0, 0, -200);
//    painter.drawLine(0, 0, 100, -0);

    struct draw_data d_data;
    d_data.painter = &painter;

    union u_data data;
    data.d_data = &d_data;

    action(DRAW, data);

    this->update();
}

void MainLabel::clean()
{   
    pixmap.fill();

    this->update();
}


void MainLabel::resizeEvent(QResizeEvent *event)
{
    std::cout << "RESIZE" << std::endl;

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
