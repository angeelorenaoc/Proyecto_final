#ifndef MURO_H
#define MURO_H

#include <QGraphicsItem>
#include <QPainter>

class Muro: public QGraphicsItem, public QObject
{

    int w,h;
    int posx, posy;
    int  id;

public:
    Muro(int w_, int h_, int x, int y, int id_,QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getW() const;
    int getH() const;
    int getPosx() const;
    int getPosy() const;
};

#endif // MURO_H
