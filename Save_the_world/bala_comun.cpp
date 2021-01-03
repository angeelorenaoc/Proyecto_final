#include "bala_comun.h"
#include "mainwindow.h"

extern MainWindow *game;

Bala_comun::Bala_comun(int sentido_)
{
    sentido = sentido_;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

QRectF Bala_comun::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Bala_comun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}

int Bala_comun::getSentido() const
{
    return sentido;
}

void Bala_comun::move()
{
    if(sentido == 1)
        setPos(x()-20,y());

    if(sentido == 2)
        setPos(x()+20,y());

    if(sentido == 3)
        setPos(x(),y()-20);

    if(sentido == 4)
        setPos(x(),y()+20);
}
