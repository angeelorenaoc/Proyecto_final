#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include "personaje_physics.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>

class personaje: public QObject, public QGraphicsItem
{
    personaje_physics * esf;
    float escala;

    Q_OBJECT
public:
    personaje();
    ~personaje();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void setPosx(int value);
    void setPosy(int value);

    void setEscala(float s);
    void actualizar(float v_lim);
    personaje_physics *getEsf();
};

#endif // PERSONAJE_H
