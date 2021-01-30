#include "escudo_graf.h"

escudo_graf::escudo_graf(float x, float y, float vx, float vy)
{
    //Se crea una instacia de la clase Escudos_fisica
    esc = new Escudos_fisica(x,y,vx,vy);
}

QRectF escudo_graf::boundingRect() const
{
    return QRectF(-esc->getR(),-esc->getR(),2*esc->getR(),2*esc->getR());
}

void escudo_graf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

void escudo_graf::actualizar(float dt)
{
    // Se actualiza la posicion del escudo en pantalla
    esc->actualizar(dt);
    setPos(esc->getPX(),esc->getPY());
}

Escudos_fisica *escudo_graf::getEsf()
{
    return esc;
}
