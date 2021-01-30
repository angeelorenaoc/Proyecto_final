#include "monedas.h"

Monedas::Monedas(int x, int y)
{
    //Se posiciona el objeto
    posx = x;
    posy = y;
    setPos(posx,posy);

    //**********************Sprite******************************
    columnas = 0;
    timer = new QTimer();
    pixmap = new QPixmap(":/new/Imagenes/Sprite_moneda.png");
    setScale(0.5);

    timer->start(100);
    connect(timer,&QTimer::timeout,this,&Monedas::Actualizar);
    //**********************************************************
}

QRectF Monedas::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Monedas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Monedas::Actualizar()
{
    //Maneja la posiciones en el sprite
    columnas+=75;
    if(columnas>600){
        columnas=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

int Monedas::getR() const
{
    return r;
}

void Monedas::setR(int value)
{
    r = value;
}

int Monedas::getPosx() const
{
    return posx;
}

void Monedas::setPosx(int value)
{
    posx = value;
}

int Monedas::getPosy() const
{
    return posy;
}

void Monedas::setPosy(int value)
{
    posy = value;
}
