#include "enemigos_sgraph.h"

Enemigos_sGraph::Enemigos_sGraph()
{
    float posx,posy,velx,vely,masa,r,K,e,rr;
    posx = 800;
    posy = 0;
    setPos(posx,posy);
    r = 20;
    masa = 50;
    velx = -10;
    vely = 0;
    K = 0.08;
    e = 0.09;
    rr = 10;
    enemy = new Enemigos_saltarines(posx,posy,velx,vely,masa,r,K,e,rr);

}
void Enemigos_sGraph::actualizar(float v_limit)
{
    enemy->Actualizar();
    setPos(enemy->getPx(),v_limit-enemy->getPy());
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
    enemy->set_vel(-30,90,enemy->getPx(),enemy->getPy());
}
