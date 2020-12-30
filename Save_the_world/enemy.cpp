#include "enemy.h"

enemy::enemy():escala(1)
{
    float posx,posy,velx,vely,mass,r,K,e;

    posx = 400;
    posy = 10;
    r = 20;
    mass = 10;
    velx = 0;
    vely = 0;
    K = 0.002;
    e = 0.2;
    esf = new enemy_physics(posx,posy,velx,vely,mass,r,K,e);
}

enemy::~enemy()
{
    delete esf;
}

QRectF enemy::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());
}

void enemy::setEscala(float s)
{
    escala = s;
}

void enemy::actualizar(float v_lim)
{
    esf->Actualizar();
    setPos(esf->getPX(),v_lim-esf->getPY());
}

enemy_physics *enemy::getEsf()
{
    return esf;
}
