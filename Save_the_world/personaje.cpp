#include "personaje.h"

personaje::personaje()
{

}

QRectF personaje::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void personaje::up()
{
    posy-= velocidad;
    setPos(posx,posy);
}

void personaje::down()
{
    posy+= velocidad;
    setPos(posx,posy);
}

void personaje::left()
{
    posx-= velocidad;
    setPos(posx,posy);
}

void personaje::right()
{
    posx+= velocidad;
    setPos(posx,posy);
}

void personaje::setPosx(int value)
{
    posx = value;
}

void personaje::setPosy(int value)
{
    posy = value;
}
