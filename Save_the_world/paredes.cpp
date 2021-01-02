#include "paredes.h"

paredes::paredes(int w_, int h_, int x, int y)
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;
}

QRectF paredes::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void paredes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawRect(boundingRect());
}
