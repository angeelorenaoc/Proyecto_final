#include "enemigos_sgraph.h"

Enemigos_sGraph::Enemigos_sGraph()
{
    float posx,posy,velx,vely,masa,r,K,e,rr;
    posx = 50;
    posy = 50;
    r = 40;
    masa = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.09;
    rr = 10;
    enemy = new Enemigos_saltarines(posx,posy,velx,vely,masa,r,K,e,rr);
}

Enemigos_sGraph::~Enemigos_sGraph()
{
    delete enemy;
}

QRectF Enemigos_sGraph::boundingRect() const
{
    return QRectF(-1*enemy->getR(),-1*enemy->getR(),2*enemy->getR(), 2*enemy->getR());
}

void Enemigos_sGraph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

Enemigos_saltarines *Enemigos_sGraph::getEnemy() const
{
    return enemy;
}

void Enemigos_sGraph::up()
{
    enemy->set_vel(25,30,enemy->getPx(),enemy->getPy());
}
