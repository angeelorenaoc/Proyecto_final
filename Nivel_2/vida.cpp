#include "vida.h"

Vida::Vida(QGraphicsItem *parent)
{
    vida = 10;
    setPlainText(QString("Vida: ")+ QString::number(vida));//COnvertir entero a string
    setDefaultTextColor(Qt::white);
    setFont(QFont("Tekton Pro",16));
    setPos(Px,Py);
}

void Vida::decrease_vida(int p)
{
    vida = vida - p;
    setPlainText(QString("Vida: ")+QString::number(vida));
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
