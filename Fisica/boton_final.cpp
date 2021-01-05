#include "boton_final.h"

Boton_final::Boton_final(QObject *parent) : QObject(parent)
{
    alto =250;
    ancho=150;
}

QRectF Boton_final::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Boton_final::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/new/fondo/Boton.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
