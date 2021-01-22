#include "muro.h"

Muro::Muro(int w_,int h_, int pox, int poy, int id_, QObject *parent) : QObject(parent)
{
    w = w_;
    h = h_;
    posx = pox;
    posy = poy;
    setPos(posx,posy);
    id = id_;//Variable que indica el numero del nivel para definir la forma de los muros
//    alto =250; - Ancho y alto del boton final
//    ancho=150;
}

QRectF Muro::boundingRect() const
{
    return QRectF(0,0,w,h);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
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
