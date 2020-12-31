#include "enemy.h"

#include <QDebug>

enemy::enemy()
{
    int random_number=rand()%2;

    if(random_number==0){
        random_number = rand()%560+1;
        setPos(560,random_number);
    }
    else{
        random_number = rand()%560+1;
        setPos(800,random_number);
    }
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

int enemy::getPosx() const
{
    return posx;
}

int enemy::getPosy() const
{
    return posy;
}

int enemy::getR() const
{
    return r;
}

int enemy::getVelocidad() const
{
    return velocidad;
}
void enemy::setPosx(int value)
{
    posx = value;
}

void enemy::setPosy(int value)
{
    posy = value;
}



