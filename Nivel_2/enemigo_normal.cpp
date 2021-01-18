#include "enemigo_normal.h"

Enemigo_normal::Enemigo_normal(QObject *parent): QObject(parent)
{
    int random_number = rand()% 400+10;
    setPos(800,random_number);
    PX=800;PY=random_number;

    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/Perro_sprite.png");
    setScale(0.8);

    timer= new QTimer;
    connect(timer,&QTimer::timeout,this,&Enemigo_normal::Actualizar);
    timer->start(50);
}

void Enemigo_normal::Actualizar()
{
    columnas += 95;
    if(columnas >= 190)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Enemigo_normal::boundingRect() const
{
    return QRect(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo_normal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::darkGreen);
//    painter->drawEllipse(boundingRect());

    QPixmap salta;
    salta.load(":/Imagenes/Perro_sprite.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
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
