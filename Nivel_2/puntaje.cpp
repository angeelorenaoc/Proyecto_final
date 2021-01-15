#include "puntaje.h"
#include <QFont>

Puntaje::Puntaje(QGraphicsItem *parent, int colorp, int id_ ): QGraphicsTextItem(parent)
{
    id=id_;
    score = 0;
    color = colorp;
    if (id == 0) {
        setPlainText(QString("Puntaje: ")+ QString::number(score));
        setFont(QFont("times",16));
    }
    else {
        setPlainText(QString("Velocidad: ")+ QString::number(score));
        setFont(QFont("times",10));
    }

    if (color == 1) {setDefaultTextColor(Qt::darkMagenta);}

    else {setDefaultTextColor(Qt::red);}

}

void Puntaje::increase(int s)
{
    score+=s;
    if (id == 0) {
        setPlainText(QString("Puntaje: ")+ QString::number(score));
        setFont(QFont("times",16));
    }
    else {
        setPlainText(QString("Velocidad: ")+ QString::number(score));
        setFont(QFont("times",10));
    }
}

int Puntaje::getPuntaje()
{
    return score;
}

void Puntaje::setScore(int value)
{
    score = value;
}

void Puntaje::setColor(int value)
{
    color = value;
}
