#ifndef VIDA_H
#define VIDA_H
#include <QGraphicsTextItem>

class Vida: public QGraphicsTextItem
{
public:
    Vida(QGraphicsItem * parent = 0,int id=0);
    void decrease();
    void increse();
    int getVida();
    int getPx() const;
    int getPy() const;
    void setPx(int value);
    void setPy(int value);

private:
    int px;
    int py;
    int vida;
};

#endif // VIDA_H
