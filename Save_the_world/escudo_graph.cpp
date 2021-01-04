#include "escudo_graph.h"

escudo_graph::escudo_graph(float x, float y, float vx, float vy)
{
    esc = new escudo(x,y,vx,vy);
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

escudo *escudo_graph::getEsf()
{
    return esc;
}
