#ifndef VIDA_H
#define VIDA_H
#include <QGraphicsTextItem>

class Vida: public QGraphicsTextItem
{
public:
    Vida(QGraphicsItem * parent = 0);
    void decrease();
    int getVida();
    int getPx() const;
    int getPy() const;

private:
    int px;
    int py;
    int vida;
};

#endif // VIDA_H
