#include "vida.h"

Vida::Vida(QGraphicsItem *parent)
{
    vida = 10;
//    setPlainText(QString("Vida: ")+ QString::number(vida));//COnvertir entero a string
//    setDefaultTextColor(Qt::white);
//    setFont(QFont("Tekton Pro",16));

    pixmap = new QPixmap(":/Imagenes/sprite_Vida.png");
    setScale(0.85);
    columnas = 0;
    setPos(Px,Py);
}

QRectF Vida::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Vida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap can;
    can.load(":/Imagenes/sprite_Vida.png");
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

void Vida::decrease_vida(int p)
{
    vida = vida - p;
//    setPlainText(QString("Vida: ")+QString::number(vida));
    if(columnas<=1431 && p==2){
        columnas+=159*p;
    }
    else if(columnas < 1749){
        columnas+=159;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

int Vida::getPx() const
{
    return Px;
}

void Vida::setPx(int value)
{
    Px = value;
}

int Vida::getPy() const
{
    return Py;
}

void Vida::setPy(int value)
{
    Py = value;
}

int Vida::getVida() const
{
    return vida;
}
