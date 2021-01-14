#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsTextItem>
#include <QFont>

class Vida: public QGraphicsTextItem
{
    int vida;
    int Px, Py;
public:
    Vida(QGraphicsItem * parent=0);

    void decrease_vida(int p);

    int getVida() const;

    int getPx() const;
    int getPy() const;

    void setPx(int value);
    void setPy(int value);
};

#endif // VIDA_H
