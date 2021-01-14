#include "puntaje.h"

puntaje::puntaje(QGraphicsItem *parent, int colorp ): QGraphicsTextItem(parent)
{
    score = 0;
    color = colorp;
    setPlainText(QString("PUNTAJE: ")+ QString::number(score));

    if (color == 0){setDefaultTextColor(Qt::darkGreen);}

    else{setDefaultTextColor(Qt::red);}

    setFont(QFont("times",15));
}

void puntaje::increase()
{
    score+=5;
    setPlainText(QString("PUNTAJE: ")+ QString::number(score));
}

void puntaje::increse_low()
{
    score+=1;
    setPlainText(QString("PUNTAJE: ")+ QString::number(score));
}

int puntaje::getpuntaje()
{
    return score;
}

void puntaje::setScore(int value)
{
    score = value;
}

void puntaje::setColor(int value)
{
    color = value;
}
