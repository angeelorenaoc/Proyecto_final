#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include "personaje.h"
#include <QTimer>

class enemy: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=2;
    int r=9;

    Q_OBJECT
public:
    enemy();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void setPosx(float value);
    void setPosy(float value);
    float getPosx() const;
    float getPosy() const;
    int getR() const;

    int getVelocidad() const;

};

#endif // ENEMY_H
