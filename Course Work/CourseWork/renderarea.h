#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

//#include "action.h"

class MainLabel : public QLabel
{

public:
    explicit MainLabel(QWidget *parent = nullptr);

    QPixmap* getPixmap();

    void draw();
    void clean();

private:
    QPixmap _pixmap;

    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

};


#endif // RENDERAREA_H
