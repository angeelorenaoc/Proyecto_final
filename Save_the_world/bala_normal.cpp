#include "bala_normal.h"

Bala_normal::Bala_normal(int sentido_)
{
    sentido = sentido_;

    //Por medio de un timer se actualiza la posicion de la bala
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
    //**********************************************************

    ancho=94;
    alto =49;
    pixmap = new QPixmap(":/new/Imagenes/Disparo.png");
    setScale(0.3);
}

QRectF Bala_normal::boundingRect() const
{
    return QRectF(-ancho,-alto,2*ancho,2*alto);
}

void Bala_normal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}

int Bala_normal::getId() const
{
    return id;
}

void Bala_normal::setId(int value)
{
    id = value;
}

int Bala_normal::getSentido() const
{
    return sentido;
}

void Bala_normal::move()
{
    /* Dependiendo del sentido que lleva la bala
     * se restan posiciones y se actualiza en la
     * escena la nueva posicion.
     * A traves del setRotation se rota la imagen
     * para que concuerde con el sentido.
    */

    if(sentido == 1){
        setRotation(180);
        setPos(x()-20,y());
    }

    if(sentido == 2){
        setPos(x()+20,y());
    }

    if(sentido == 3){
        setRotation(270);
        setPos(x(),y()-20);
    }

    if(sentido == 4){
        setRotation(90);
        setPos(x(),y()+20);
    }
}
