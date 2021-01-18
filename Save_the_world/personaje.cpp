#include "personaje.h"

int personaje::getAngulo() const
{
    return angulo;
}

int personaje::getVel_inicial() const
{
    return vel_inicial;
}

personaje::personaje(int id_)
{
    id=id_;
    columnas=0;
    filas=0;
    ancho = 60;
    alto = 95;

    if(id==0)
        pixmap = new QPixmap(":/Imagenes/Sprite_medico_1.png");
    else
        pixmap = new QPixmap(":/Imagenes/Sprite_medico2.png");

    setScale(0.6);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &personaje::Actualizar_sprite);
    timer->start(150);

}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawEllipse(boundingRect());

    QPixmap doctor;
    if(id==0)
        doctor.load(":/Imagenes/Sprite_medico_1.png");
    else
        doctor.load(":/Imagenes/Sprite_medico2.png");

    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void personaje::Actualizar_sprite()
{
    columnas += 60;
    if(columnas >= 540){
        columnas = 0;
    }

    this->update(-ancho/2,-alto/2,ancho,alto);
}

void personaje::up()
{
    posy-= velocidad;
    filas=95;
    setPos(posx,posy);
}

void personaje::down()
{
    posy+= velocidad;
    filas=0;
    setPos(posx,posy);
}

void personaje::left()
{
    posx-= velocidad;
    filas=285;
    setPos(posx,posy);
}

void personaje::right()
{
    posx+= velocidad;
    filas=190;
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
