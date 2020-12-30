#include "personaje.h"

personaje::personaje():escala(1)
{
    float posx,posy,velx,vely,mass,r,K,e;

    posx = 32;
    posy = 150;
    r = 20;
    mass = 100;
    velx = 0;
    vely = 0;
    K = 0.002;
    e = 0.02;
    esf = new personaje_physics(posx,posy,velx,vely,mass,r,K,e);
}

personaje::~personaje()
{
    delete esf;
}

QRectF personaje::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void personaje::setEscala(float s)
{
    escala = s;
}

void personaje::actualizar(float v_lim)
{
    esf->actualizar();
    setPos(esf->getPX(),v_lim-esf->getPY());
}

personaje_physics *personaje::getEsf()
{
    return esf;
}
