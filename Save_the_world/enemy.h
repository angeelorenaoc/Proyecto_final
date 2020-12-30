#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include "enemy_physics.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>

class enemy: public QObject, public QGraphicsItem
{
    enemy_physics * esf;
    float escala;

    Q_OBJECT
public:
    enemy();
    ~enemy();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setEscala(float s);
    void actualizar(float v_lim);
    enemy_physics *getEsf();
};

#endif // ENEMY_H
