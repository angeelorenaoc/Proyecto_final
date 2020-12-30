#include "enemigosgraf.h"

Enemigosgraf::Enemigosgraf():escala(1)
{
    float posx,posy,velx,vely,masa,r,K,e;
    posx = 32;
    posy = 30;
    r = 20;
    masa = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.1;
    esf = new Enemigos(posx,posy,velx,vely,masa,r,K,e);
}

Enemigosgraf::~Enemigosgraf()
{
    delete esf;
}

QRectF Enemigosgraf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(), 2*escala*esf->getR());
}

void Enemigosgraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

void Enemigosgraf::setescala(float s)
{
    escala = s;
}

void Enemigosgraf::actualizar(float v_limit)
{
    esf->Actualizar();
    setPos(esf->getPx(),v_limit-esf->getPy());
}

Enemigos *Enemigosgraf::getEsf()
{
    return esf;
}

void Enemigosgraf::setImagen(int value)
{
    imagen = value;
}
