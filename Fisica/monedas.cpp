#include "monedas.h"

monedas::monedas(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);

    columnas = 0;
    timer = new QTimer();
    pixmap = new QPixmap(":/new/fondo/Sprite_moneda.png");
    setScale(0.5);

    timer->start(100);
    connect(timer,&QTimer::timeout,this,&monedas::Actualizar);
}

QRectF monedas::boundingRect() const
{
    //return QRectF(-r,-r,2*r,2*r);
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void monedas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::yellow);
//    painter->drawEllipse(boundingRect());

    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void monedas::Actualizar()
{
    columnas+=75;
    if(columnas>600){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
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
