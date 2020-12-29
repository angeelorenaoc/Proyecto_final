#include "vida.h"
#include <QFont>


Vida::Vida(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    vida = 3;
    setPlainText(QString("Vida ")+ QString::number(vida));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Vida::decrease()
{
    vida--;
    setPlainText(QString("Vida: ")+ QString::number(vida));
}

int Vida::getVida()
{
    return vida;
}

int Vida::getPx() const
{
    return px;
}

int Vida::getPy() const
{
    return py;
}
