#ifndef ENEMIGO_NORMAL_H
#define ENEMIGO_NORMAL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Enemigo_normal: public QObject, public QGraphicsItem
{
    int PX,PY;
    int Vel=3;
    int r=10;

public:
    Enemigo_normal();

    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move();

    int getPX() const;
    int getPY() const;
    void setPX(int value);
    void setPY(int value);
};
#endif // ENEMIGO_NORMAL_H
