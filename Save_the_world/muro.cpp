#include "muro.h"

Muro::Muro(int w_,int h_, int pox, int poy, int id_, QObject *parent) : QObject(parent)
{
    w = w_;
    h = h_;
    posx = pox;
    posy = poy;
    setPos(posx,posy);
    id = id_;
}

QRectF Muro::boundingRect() const
{
    return QRectF(0,0,w,h);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Si id es 3 se trata de un muro, si es 2 se trata del gran boton (objetivo en el nivel 3)
    if (id == 3){painter->fillRect(boundingRect(),Qt::black);}
    else if (id == 2){
        QPixmap pixmap;
        pixmap.load(":/new/Imagenes/Boton.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
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
