#include "cuerpograf.h"

Cuerpograf::Cuerpograf():escala(1) //Para escalar la imagen
{
    float posx,posy,velx,vely,masa,r,K,e;
    posx = 32;
    posy = 30;
    r = 20;
    masa = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;
    esf = new Cuerpo(posx,posy,velx,vely,masa,r,K,e);
}

Cuerpograf::~Cuerpograf()
{
    delete esf;
}

QRectF Cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(), 2*escala*esf->getR());
}

void Cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void Cuerpograf::setescala(float s)
{
    escala = s;
}

void Cuerpograf::actualizar(float v_limit)
{
    esf->Actualizar();
    setPos(esf->getPx(),v_limit-esf->getPy());
}

Cuerpo *Cuerpograf::getEsf()
{
    return esf;
}
