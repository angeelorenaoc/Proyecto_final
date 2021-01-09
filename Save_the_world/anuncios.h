#ifndef ANUNCIOS_H
#define ANUNCIOS_H

#include <QGraphicsTextItem>
#include <QFont>

class anuncios: public QGraphicsTextItem
{
//    int score;
//    int Px_S, Py_S;

    int vida;
    int Px_V, Py_V;
public:
    anuncios(QGraphicsItem * parent=0);
    void increase_score();
    void decrease_vida();

    int getScore() const;
    int getVida() const;

//    int getPx_S() const;
//    int getPy_S() const;
    int getPy_V() const;
    int getPx_V() const;

//    void setPx_S(int value);
//    void setPy_S(int value);
    void setPx_V(int value);
    void setPy_V(int value);
};

#endif // ANUNCIOS_H
