#include "qtdrawer.h"

namespace drawer {

QtDrawer::QtDrawer(QPainter *painter)
{
    this->_painter = painter;
}


void QtDrawer::setColor(int r, int g, int b)
{
    _painter->setPen(QColor(r, g, b));
}


void QtDrawer::drawPoint(int x, int y) const
{
    this->_painter->drawPoint(x, y);
}

}
