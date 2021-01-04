#include "cuerpograf.h"

Cuerpograf::Cuerpograf(QObject *parent) : QObject(parent), escala(1) //Para escalar la imagen
{
    timermo = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/new/fondo/Sprite_personaje.png");

    ancho = 40;
    alto  = 76;

    float posx,posy,velx,vely,masa,r,K,e,rr;
    posx = 32;
    posy = 30;
    r = 40;
    masa = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.1;
    rr = 10;
    esf = new Cuerpo(posx,posy,velx,vely,masa,r,K,e,rr);

    timermo->start(100);
    connect(timermo,&QTimer::timeout,this,&Cuerpograf::Actualizacion);
}

Cuerpograf::~Cuerpograf()
{
    delete esf;
}

QRectF Cuerpograf::boundingRect() const
{
//    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(), 2*escala*esf->getR());
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawEllipse(boundingRect());
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
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

void Cuerpograf::setColumnas(float value)
{
    columnas = value;
}

void Cuerpograf::setFilas(float value)
{
    filas = value;
}

float Cuerpograf::getAlto() const
{
    return alto;
}

float Cuerpograf::getAncho() const
{
    return ancho;
}

void Cuerpograf::Actualizacion()
{
    columnas += 40;
    if(columnas >= 360)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
