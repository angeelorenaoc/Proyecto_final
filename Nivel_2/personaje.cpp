#include "personaje.h"

Personaje::Personaje(QObject *parent,int _px, int _py,int fil) : QObject(parent)
{
    PX = _px;
    PY = _py;
    setPos(PX,PY);

    angulo=45;
    vel_inicial=0;

    timer = new QTimer();
    if(fil==1)
        filas = 0;
    else
        filas = 100;
    columnas = 1200;
    pixmap = new QPixmap(":/Imagenes/Sprite_canon.png");
    setScale(0.8);
    setRotation(45);

    connect(timer,&QTimer::timeout,this,&Personaje::Actualizar);
}

void Personaje::Actualizar()
{
    columnas += 100;
    if(columnas >= 1300)
    {
        columnas =1200;
        timer->stop();
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

int Personaje::getFilas() const
{
    return filas;
}

void Personaje::setFilas(int value)
{
    filas = value;
}

int Personaje::getColumnas() const
{
    return columnas;
}

void Personaje::setColumnas(int value)
{
    columnas = value;
}

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawEllipse(boundingRect());

    QPixmap can;
    can.load(":/Imagenes/Sprite_canon.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void Personaje::disparo()
{
    columnas=0;
    timer->start(100);
}

void Personaje::up()
{
    angulo+=5;
    setRotation(90-angulo);
}

void Personaje::down()
{
    angulo-=5;
    setRotation(90-angulo);
}

void Personaje::left()
{
    vel_inicial-=5;
}

void Personaje::right()
{
    vel_inicial+=5;
}

int Personaje::getPX() const
{
    return PX;
}

int Personaje::getPY() const
{
    return PY;
}

int Personaje::getAngulo() const
{
    return angulo;
}

int Personaje::getVel_inicial() const
{
    return vel_inicial;
}
