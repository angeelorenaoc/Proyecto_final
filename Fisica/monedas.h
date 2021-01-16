#ifndef MONEDAS_H
#define MONEDAS_H

#include <QGraphicsItem>
#include <QPainter>

class monedas: public QGraphicsItem
{

    int r=10;
    int posx, posy;

public:
    monedas(int x, int y);

    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};
#endif // MONEDAS_H
