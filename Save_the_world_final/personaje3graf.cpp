#include "personaje3graf.h"

Personaje3graf::Personaje3graf(QObject *parent, int id) : QObject(parent)
{
    timermo = new QTimer();
    filas = 0;
    columnas = 0;
    // Dependiendo del id se le da la imagen al personaje
    if (id == 0){
        pixmap = new QPixmap(":/new/Imagenes/Sprite_personaje.png");}
    else{
        pixmap = new QPixmap(":/new/Imagenes/Personaje_mujer.png");}

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
    e = 0.5;
    rr = 1;

    // Se crea una instancia de la clase Personaje3
    esf = new Personaje3(posx,posy,velx,vely,masa,r,K,e,rr);

    timermo->start(100);
    connect(timermo,&QTimer::timeout,this,&Personaje3graf::Actualizacion);
}

Personaje3graf::~Personaje3graf()
{
    delete esf;
}

void Personaje3graf::actualizar(float v_limit)
{
    //Actualiza la posicion
    esf->Actualizar();
    setPos(esf->getPx(),v_limit-esf->getPy());
}

QRectF Personaje3graf::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personaje3graf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}


Personaje3 *Personaje3graf::getEsf()
{
    return esf;
}

void Personaje3graf::setColumnas(float value)
{
    columnas = value;
}

void Personaje3graf::setFilas(float value)
{
    filas = value;
}

float Personaje3graf::getAlto() const
{
    return alto;
}

float Personaje3graf::getAncho() const
{
    return ancho;
}

void Personaje3graf::Actualizacion()
{
    columnas += 40;
    if(columnas >= 360)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
