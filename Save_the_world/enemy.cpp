#include "enemy.h"

#include <QDebug>


enemy::enemy()
{
    int random_number=rand()%4;

    if(random_number==0){
        random_number = rand()%180+135;
        setPos(18,random_number);
        setPosx(18);setPosy(random_number);
    }
    else if(random_number==1){
        random_number = rand()%619+185;
        setPos(random_number,620);
        setPosx(random_number);setPosy(620);
    }
    else if(random_number==3){
        random_number = rand()%619+185;
        setPos(random_number,620);
        setPosx(random_number);setPosy(620);
    }
    else{
        random_number = rand()%81+207;
        setPos(930,random_number);
        setPosx(930);setPosy(random_number);
    }
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void enemy::up()
{
    posy-= velocidad;
    setPos(posx,posy);
}

void enemy::down()
{
    posy+= velocidad;
    setPos(posx,posy);
}

void enemy::left()
{
    posx-= velocidad;
    setPos(posx,posy);
}

void enemy::right()
{
    posx+= velocidad;
    setPos(posx,posy);
}

float enemy::getPosx() const
{
    return posx;
}

float enemy::getPosy() const
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
void enemy::setPosx(float value)
{
    posx = value;
}

void enemy::setPosy(float value)
{
    posy = value;
}




