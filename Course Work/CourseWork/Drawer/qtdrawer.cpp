#include "qtdrawer.h"

namespace drawer {

QtDrawer::QtDrawer(QPainter *painter)
{
    this->_painter = painter;
}


void QtDrawer::setColor(int r, int g, int b)
{

    r = r < 0 ? r = 0 : r > 255 ? 255 : r;
    g = g < 0 ? g = 0 : g > 255 ? 255 : g;
    b = b < 0 ? b = 0 : b > 255 ? 255 : b;

    _painter->setPen(QColor(r, g, b));
}


void QtDrawer::drawPoint(int x, int y) const
{
    this->_painter->drawPoint(x, y);
}

}
