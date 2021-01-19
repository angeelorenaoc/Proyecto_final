#include "escudo_graf.h"

escudo_graph::escudo_graph(float x, float y, float vx, float vy)
{
    esc = new Escudos_fisica(x,y,vx,vy);
}

QRectF escudo_graph::boundingRect() const
{
    return QRectF(-esc->getR(),-esc->getR(),2*esc->getR(),2*esc->getR());
}

void escudo_graph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

void escudo_graph::actualizar(float dt)
{
    esc->actualizar(dt);
    setPos(esc->getPX(),esc->getPY());
}

Escudos_fisica *escudo_graph::getEsf()
{
    return esc;
}
