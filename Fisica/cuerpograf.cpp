#include "cuerpograf.h"

Cuerpograf::Cuerpograf(QObject *parent) : QObject(parent), escala(1) //Para escalar la imagen
{
    timermo = new QTimer();
    filas = 65;
    columnas = 0;
    pixmap = new QPixmap(":/new/fondo/Personajehombrerecortada_3.png");

    ancho = 64;
    alto  = 65;

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

void Cuerpograf::Actualizacion()
{
    columnas += 64;
    if(columnas >= 576)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
