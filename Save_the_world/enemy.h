#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include "personaje.h"
#include <QTimer>

class enemy: public QObject, public QGraphicsItem
{
    int posx ,posy;
    int velocidad=2;
    int r=20;

    Q_OBJECT
public:
    enemy();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void setPosx(int value);
    void setPosy(int value);
    int getPosx() const;
    int getPosy() const;
    int getR() const;

    int getVelocidad() const;

};

#endif // ENEMY_H
