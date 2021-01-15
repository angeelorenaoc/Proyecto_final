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

    pixmap = new QPixmap(":/Imagenes/bala_canon.png");
    setScale(0.13);

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
    return QRectF(-r_sprite,-r_sprite,2*r_sprite, 2*r_sprite);
}

void Bala_graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::darkGray);
//    painter->drawEllipse(boundingRect());

    QPixmap bala;
    bala.load(":/Imagenes/bala_canon.png");
    painter->drawPixmap(-r_sprite,-r_sprite,*pixmap,0,0,2*r_sprite,2*r_sprite);
}

