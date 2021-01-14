#ifndef ANUNCIOS_H
#define ANUNCIOS_H

#include <QGraphicsTextItem>
#include <QFont>

class anuncios: public QGraphicsTextItem
{
    int vida;
    int Px_V, Py_V;
public:
    anuncios(QGraphicsItem * parent=0);
    void decrease_vida();

    int getScore() const;
    int getVida() const;

    int getPy_V() const;
    int getPx_V() const;

    void setPx_V(int value);
    void setPy_V(int value);
};

#endif // ANUNCIOS_H
