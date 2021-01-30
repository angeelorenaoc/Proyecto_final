#include "bala_parabolica_graf.h"

Bala_parabolica_graf::Bala_parabolica_graf(float px, float py, float ang, float v)
{
    //Se definen los datos por defecto al objeto
    float posx,posy,masa,r,K,e;
    posx = px;
    posy = py;
    setPos(posx,posy);
    r = 5;
    masa = 50;
    K = 0.08;
    e = 0.09;

    //Se crea un instacia de la clase bala_parabolica
    bala = new Bala_parabolica(posx,posy,masa,r,K,e,ang,v);

    pixmap = new QPixmap(":/new/Imagenes/bala_canon.png");
    setScale(0.13);

}
//Se reccibe el v_limit para definir hacia donde debe caer el bala
void Bala_parabolica_graf::actualizar(float v_limit)
{
    //Se actualiza la posicion de la bala en la pantalla
    bala->ActualizarPosicion();
    setPos(bala->getPx(),v_limit-bala->getPy());
}

int Bala_parabolica_graf::getId() const
{
    return id;
}

void Bala_parabolica_graf::setId(int value)
{
    id = value;
}

Bala_parabolica *Bala_parabolica_graf::getBala() const
{
    return bala;
}

Bala_parabolica_graf::~Bala_parabolica_graf()
{
    delete bala;
}

QRectF Bala_parabolica_graf::boundingRect() const
{
    return QRectF(-r_sprite,-r_sprite,2*r_sprite, 2*r_sprite);
}

void Bala_parabolica_graf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-r_sprite,-r_sprite,*pixmap,0,0,2*r_sprite,2*r_sprite);
}
