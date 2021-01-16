#include "monedas.h"

monedas::monedas(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
}

int monedas::getR() const
{
    return r;
}

void monedas::setR(int value)
{
    r = value;
}

int monedas::getPosx() const
{
    return posx;
}

void monedas::setPosx(int value)
{
    posx = value;
}

int monedas::getPosy() const
{
    return posy;
}

void monedas::setPosy(int value)
{
    posy = value;
}

QRectF monedas::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void monedas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}
