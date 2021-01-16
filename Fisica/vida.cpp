#include "vida.h"
#include <QFont>


Vida::Vida(QGraphicsItem *parent,int id): QGraphicsTextItem(parent)
{   
    if(id==0){
        vida = 3;
        setPlainText(QString("Vida: ")+ QString::number(vida));
        setDefaultTextColor(Qt::green);
        setFont(QFont("times",16));
    }
    else{
        vida = 0;
        setPlainText(QString("Puntaje: ")+ QString::number(vida));
        setDefaultTextColor(Qt::cyan);
        setFont(QFont("times",16));
    }
}

void Vida::decrease()
{
    vida--;
    setPlainText(QString("Vida: ")+ QString::number(vida));
}

void Vida::increse()
{
    vida+=10;
    setPlainText(QString("Puntaje: ")+ QString::number(vida));
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

void Vida::setPx(int value)
{
    px = value;
}

void Vida::setPy(int value)
{
    py = value;
}
