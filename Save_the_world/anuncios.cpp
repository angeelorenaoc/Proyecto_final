#include "anuncios.h"

anuncios::anuncios(QGraphicsItem *parent)
{
//    score=0;
//    setPlainText(QString("Score: ")+ QString::number(score));//COnvertir entero a string
//    setDefaultTextColor(Qt::darkBlue);
//    setFont(QFont("Tekton Pro",25));
//    setPos(Px_S,Py_S);

    vida = 3;
    setPlainText(QString("Vida: ")+ QString::number(vida));//COnvertir entero a string
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("Tekton Pro",10));
    setPos(Px_V,Py_V);
}

//void anuncios::increase_score()
//{
//    score++;
//    setPlainText(QString("Score: ")+ QString::number(score));
//}

void anuncios::decrease_vida()
{
    vida--;
    setPlainText(QString("Vida: ")+QString::number(vida));
}

//int anuncios::getScore() const
//{
//    return score;
//}

int anuncios::getVida() const
{
    return vida;
}

//int anuncios::getPx_S() const
//{
//    return Px_S;
//}

//int anuncios::getPy_S() const
//{
//    return Py_S;
//}

int anuncios::getPx_V() const
{
    return Px_V;
}

int anuncios::getPy_V() const
{
    return Py_V;
}

//void anuncios::setPy_S(int value)
//{
//    Py_S = value;
//}

//void anuncios::setPx_S(int value)
//{
//    Px_S = value;
//}

void anuncios::setPx_V(int value)
{
    Px_V = value;
}

void anuncios::setPy_V(int value)
{
    Py_V = value;
}
