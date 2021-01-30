#include "vida_ii.h"

Vida_II::Vida_II(QGraphicsItem *parent)
{
    //El sprite hace las veces de vida
    vida = 10;
    pixmap = new QPixmap(":/new/Imagenes/sprite_Vida.png"); //Se carga la imagen
    setScale(0.85); //Se escala para que ajuste mejor en la pantalla (no se vea muy grande)
    columnas = 0;
}

QRectF Vida_II::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Vida_II::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*El sprite de la vida solo se invoca en el nivel 2*/
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Vida_II::decrease_vida(int i)
{
    /*Permite recorrer el sprite evitando la situacion de cuando columnas toma
        valores inexistentes en la imagen*/
    vida-=i;
    if(columnas<=1431 && i==2){
        columnas+=159*i;
    }
    else if(columnas < 1749){
        columnas+=159;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

int Vida_II::getVida() const
{
    return vida;
}
