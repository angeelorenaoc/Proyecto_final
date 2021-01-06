#include "personaje.h"

Personaje::Personaje(int _px, int _py)
{
    PX = _px;
    PY = _py;
    setPos(PX,PY);

    angulo=45;
    vel_inicial=0;
}

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void Personaje::up()
{
    angulo+=5;
}

void Personaje::down()
{
    angulo-=5;
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
