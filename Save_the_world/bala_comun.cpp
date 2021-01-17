#include "bala_comun.h"

Bala_comun::Bala_comun(int sentido_)
{
    sentido = sentido_;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    ancho=94;
    alto =49;
    pixmap = new QPixmap(":/Imagenes/Disparo.png");
    setScale(0.3);
}

QRectF Bala_comun::boundingRect() const
{
    return QRectF(-ancho,-alto,2*ancho,2*alto);
}

void Bala_comun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::cyan);
//    painter->drawEllipse(boundingRect());

    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}

int Bala_comun::getId() const
{
    return id;
}

void Bala_comun::setId(int value)
{
    id = value;
}

int Bala_comun::getSentido() const
{
    return sentido;
}

void Bala_comun::move()
{
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
