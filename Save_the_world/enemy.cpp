#include "enemy.h"

#include <QDebug>

enemy::enemy()
{
    int random_number=rand()%3;

    if(random_number==0){
        random_number = rand()%170+135;
        setPos(21,random_number);
        setPosx(21);setPosy(random_number);
    }
    else if(random_number==1){
        random_number = rand()%619+185;
        setPos(random_number,600);
        setPosx(random_number);setPosy(600);
    }
    else{
        random_number = rand()%70+207;
        setPos(920,random_number);
        setPosx(920);setPosy(random_number);
    }
    columnas=0;

    pixmap = new QPixmap(":/Imagenes/Covid.png");
    setScale(0.45);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &enemy::Actualizar_sprite);
    timer->start(150);
}

QRectF enemy::boundingRect() const
{
    return QRectF(-r,-r,5*r,5*r);
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::darkGreen);
//    painter->drawEllipse(boundingRect());

    QPixmap ghost;
    ghost.load(":/Imagenes/Covid.png");
    painter->drawPixmap(-r,-r,*pixmap,columnas,0,r*5,r*5);
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

void enemy::Actualizar_sprite()
{
    columnas += 100;
    if(columnas >= 200){
        columnas = 0;
    }
    this->update(-r,-r,r*5,r*5);
}
void enemy::setPosx(float value)
{
    posx = value;
}

void enemy::setPosy(float value)
{
    posy = value;
}




