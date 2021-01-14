#include "personaje.h"

personaje::personaje()
{
    //    int columnas,filas;
//    QTimer *timer;
//    QPixmap *pixmap;

//    columnas=0;
//    filas=0;

//    pixmap = new QPixmap(":/Imagenes/Personaje_Medico_sprite.png");
//    setScale(0.45);

//    timer = new QTimer();
//    connect(timer, &QTimer::timeout, this, &personaje::Actualizar_sprite);
//    timer->start(150);

}

QRectF personaje::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());

//    QPixmap doctor;
//    doctor.load(":/Imagenes/Personaje_Medico_sprite.png");
//    painter->drawPixmap(-r,-r,*pixmap,columnas,filas,r*5,r*5);
}

//void personaje::Actualizar_sprite()
//{
//    columnas += 100;
//    if(filas<=300){
//        if(columnas >= 800){
//            columnas = 0;
//        }
//    }
//    else if(filas <= 700 && filas>=500){
//        if(columnas >= 900){
//            columnas = 0;
//        }
//    }
//    else if(filas <= 1200 && filas>=800){
//        if(columnas >= 600){
//            columnas = 0;
//        }
//    }

//    this->update(-r,-r,r*5,r*5);
//}

void personaje::up()
{
    posy-= velocidad;
    setPos(posx,posy);
}

void personaje::down()
{
    posy+= velocidad;
    setPos(posx,posy);
}

void personaje::left()
{
    posx-= velocidad;
    setPos(posx,posy);
}

void personaje::right()
{
    posx+= velocidad;
    setPos(posx,posy);
}

float personaje::getPosx() const
{
    return posx;
}

float personaje::getPosy() const
{
    return posy;
}

int personaje::getR() const
{
    return r;
}

void personaje::setPosx(float value)
{
    posx = value;
}

void personaje::setPosy(float value)
{
    posy = value;
}
