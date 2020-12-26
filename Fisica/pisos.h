#ifndef PISOS_H
#define PISOS_H
#include <QGraphicsItem>
#include <QPainter>


class Pisos:public QGraphicsItem
{
    int w,h;
    int pox,poy;
public:
    Pisos(int w_,int h_, int posx, int posy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPox() const;
    int getPoy() const;
    int getW() const;
    int getH() const;
};

#endif // PISOS_H
