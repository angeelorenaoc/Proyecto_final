#include "bala_graph.h"

Bala_graph::Bala_graph(float px, float py, float ang, float v)
{
    float posx,posy,masa,r,K,e;
    posx = px;
    posy = py;
    setPos(posx,posy);
    r = 5;
    masa = 50;
    K = 0.08;
    e = 0.09;
    bala = new Bala(posx,posy,masa,r,K,e,ang,v);

}
void Bala_graph::actualizar(float v_limit)
{
    bala->ActualizarPosicion();
    setPos(bala->getPx(),v_limit-bala->getPy());
}

Bala *Bala_graph::getBala() const
{
    return bala;
}

int Bala_graph::getId() const
{
    return id;
}

void Bala_graph::setId(int value)
{
    id = value;
}

Bala_graph::~Bala_graph()
{
    delete bala;
}

QRectF Bala_graph::boundingRect() const
{
    return QRectF(-1*bala->getR(),-1*bala->getR(),2*bala->getR(), 2*bala->getR());
}

void Bala_graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(boundingRect());
}

