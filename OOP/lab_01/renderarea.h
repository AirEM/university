#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

#include "action.h"

class MainLabel : public QLabel
{

public:
    explicit MainLabel(QWidget *parent = nullptr);
    //~MainLabel();
    void draw();
    void clean();

private:
    QPixmap pixmap;

    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

};


#endif // RENDERAREA_H
