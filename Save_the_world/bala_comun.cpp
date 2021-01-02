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
    painter->setBrush(Qt::darkRed);
    painter->drawEllipse(boundingRect());
}

int Bala_comun::getSentido() const
{
    return sentido;
}

void Bala_comun::move()
{                            
    if(sentido == 1){
        setPos(x()-20,y());
        if(pos().x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(sentido == 2){
        setPos(x()+20,y());
        if(pos().x() > 962){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(sentido == 3){
        setPos(x(),y()-20);
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(sentido == 4){
        setPos(x(),y()+20);
        if(pos().y() > 642){
            scene()->removeItem(this);
            delete this;
        }
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0; i< colliding_items.size();i++){
        if(typeid(*(colliding_items[i]))==typeid (enemy)){
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
        }
    }
}
