#include "enemigosgraf.h"

Enemigosgraf::Enemigosgraf(QObject *parent) : QObject(parent),escala(1)
{
    timerm = new QTimer();
    filas = 65;
    columnas = 0;
    pixmap = new QPixmap(":/new/fondo/Enemigorecortada_nivel3.png");

    ancho = 63;
    alto  = 65;

    float posx,posy,velx,vely,masa,r,K,e;
    posx = 32;
    posy = 30;
    r = 20;
    masa = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.09;
    esf = new Enemigos(posx,posy,velx,vely,masa,r,K,e);
    timerm->start(100);
    connect(timerm,&QTimer::timeout,this,&Enemigosgraf::Actualizacion);
}

Enemigosgraf::~Enemigosgraf()
{
    delete esf;
}

QRectF Enemigosgraf::boundingRect() const
{
//    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(), 2*escala*esf->getR());
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigosgraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::green);
//    painter->drawEllipse(boundingRect());
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
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


void Enemigosgraf::setFilas(float value)
{
    filas = value;
}

void Enemigosgraf::setColumnas(float value)
{
    columnas = value;
}


void Enemigosgraf::Actualizacion()
{
    columnas += 63;
    if(columnas >= 567)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
