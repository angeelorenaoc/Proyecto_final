#include "bala_graph.h"

Bala_graph::Bala_graph(double x, double y, double v, double a)
{
    bala = new Bala(x,y,v,a);

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(Actualizar()));
    timer->start(20);
}

QRectF Bala_graph::boundingRect() const
{
    return QRectF(-bala->getR(),-bala->getR(),2*bala->getR(),2*bala->getR());
}

void Bala_graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

Bala *Bala_graph::getBala() const
{
    return bala;
}

void Bala_graph::Actualizar()
{
    bala->ActualizarPosicion();
}
