#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QPainter>

#include "basedrawer.h"

namespace drawer {

class QtDrawer : public BaseDrawer
{
public:
    explicit QtDrawer(QPainter *);


    void setColor(int, int, int) override;

    void drawPoint(int, int) const override;

private:
    QPainter *_painter;
};

}

#endif // QTDRAWER_H
