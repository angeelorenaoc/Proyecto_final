#ifndef PAREDES_H
#define PAREDES_H

#include <QGraphicsItem>
#include <QPainter>

class paredes: public QGraphicsItem
{

    int w,h;
    int posx, posy;

public:
    paredes(int w_, int h_, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PAREDES_H
