#include "pisos.h"

int Pisos::getPox() const
{
    return pox;
}

int Pisos::getPoy() const
{
    return poy;
}

int Pisos::getW() const
{
    return w;
}

int Pisos::getH() const
{
    return h;
}

Pisos::Pisos(int w_,int h_, int posx, int posy)
{
    w = w_;
    h = h_;
    pox = posx;
    poy = posy;
}

QRectF Pisos::boundingRect() const
{
    return QRectF(-pox,-poy,w,h);
}

void Pisos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkGreen);
    //painter->drawRect(boundingRect());
    painter->fillRect(boundingRect(),Qt::darkGray);
}
