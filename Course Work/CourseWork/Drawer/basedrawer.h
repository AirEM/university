#ifndef BASEDRAWER_H
#define BASEDRAWER_H

namespace drawer {

class BaseDrawer
{
public:
    virtual ~BaseDrawer() = default;
    virtual void setColor(int, int, int) = 0;
    virtual void drawPoint(int, int) const = 0;
};

}

#endif // BASEDRAWER_H
