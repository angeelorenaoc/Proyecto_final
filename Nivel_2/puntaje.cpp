#include "puntaje.h"
#include <QFont>

Puntaje::Puntaje(QGraphicsItem *parent, int colorp ): QGraphicsTextItem(parent)
{
    score = 0;
    color = colorp;
    setPlainText(QString("Puntaje: ")+ QString::number(score));

    if (color == 1){setDefaultTextColor(Qt::cyan);}

    else{setDefaultTextColor(Qt::red);}

    setFont(QFont("times",16));
}

void Puntaje::increase()
{
    score++;
    setPlainText(QString("Puntaje: ")+ QString::number(score));
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
