#include "anuncios.h"

anuncios::anuncios(QGraphicsItem *parent)
{
    vida = 3;
    setPlainText(QString("Vida: ")+ QString::number(vida));//COnvertir entero a string
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("Tekton Pro",10));
    setPos(Px_V,Py_V);
}

void anuncios::decrease_vida()
{
    vida--;
    setPlainText(QString("Vida: ")+QString::number(vida));
}
int anuncios::getVida() const
{
    return vida;
}
int anuncios::getPx_V() const
{
    return Px_V;
}

int anuncios::getPy_V() const
{
    return Py_V;
}

void anuncios::setPx_V(int value)
{
    Px_V = value;
}

void anuncios::setPy_V(int value)
{
    Py_V = value;
}
