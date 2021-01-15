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

    columnas = 1200;
    pixmap = new QPixmap(":/Imagenes/Lenador_saltando.png");
    setScale(0.7);
}
void Enemigos_sGraph::actualizar(float v_limit)
{
    enemy->Actualizar();
    setPos(enemy->getPx(),v_limit-enemy->getPy());
}

void Enemigos_sGraph::sprite()
{
   if(enemy->getVy()==0)
        columnas=ancho;
   else if(enemy->getVy()>0)
       columnas=0;
   else if(enemy->getVy()<0)
       columnas=ancho*2;
}

Enemigos_sGraph::~Enemigos_sGraph()
{
    delete enemy;
}

QRectF Enemigos_sGraph::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigos_sGraph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::green);
//    painter->drawEllipse(boundingRect());

    QPixmap salta;
    salta.load(":/Imagenes/Lenador_saltando.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

Enemigos_saltarines *Enemigos_sGraph::getEnemy() const
{
    return enemy;
}

void Enemigos_sGraph::up()
{
    enemy->set_vel(-30,90,enemy->getPx(),enemy->getPy());
}
