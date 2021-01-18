#include "muro.h"

Muro::Muro(int w_,int h_, int pox, int poy, int id_)
{
    w = w_;
    h = h_;
    posx = pox;
    posy = poy;
    id = id_;//Variable que indica el numero del nivel para definir la forma de los muros
}

QRectF Muro::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (id == 3){painter->fillRect(boundingRect(),Qt::black);}
}

int Muro::getH() const
{
    return h;
}

int Muro::getPosx() const
{
    return posx;
}

int Muro::getPosy() const
{
    return posy;
}

int Muro::getW() const
{
    return w;
}
