#include "bala_graph.h"

Bala_graph::Bala_graph(int px_, int py_, int v_, int a_)
{
    bala = new Bala(px_,py_,v_,a_);
    setPos(px_,py_);

//    QTimer *timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
//    timer->start(50);
}

Bala_graph::~Bala_graph()
{
    delete bala;
}

QRectF Bala_graph::boundingRect() const
{
    return QRectF(-bala->getR(),-bala->getR(),2*bala->getR(),2*bala->getR());
}

void Bala_graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}

//void Bala_graph::move()
//{
//    bala->ActualizarPosicion();
//    setPos(bala->getPosx(),bala->getPosy());
//}

Bala *Bala_graph::getBala() const
{
    return bala;
}
