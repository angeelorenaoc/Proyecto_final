#include "enemigo_normal.h"

Enemigo_normal::Enemigo_normal()
{
    int random_number = rand()% 400+10;
    setPos(800,random_number);
    PX=800;PY=random_number;
}

QRectF Enemigo_normal::boundingRect() const
{
    return QRect(-r,-r,2*r,2*r);
}

void Enemigo_normal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void Enemigo_normal::move()
{
    PX-=Vel;
    setPos(PX,PY);
}

int Enemigo_normal::getPX() const
{
    return PX;
}

int Enemigo_normal::getPY() const
{
    return PY;
}

void Enemigo_normal::setPX(int value)
{
    PX = value;
}

void Enemigo_normal::setPY(int value)
{
    PY = value;
}
