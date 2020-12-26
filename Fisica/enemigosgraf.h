#ifndef ENEMIGOSGRAF_H
#define ENEMIGOSGRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include "enemigos.h"

class Enemigosgraf: public QObject, public QGraphicsItem
{
public:
    Enemigosgraf();
    ~Enemigosgraf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Enemigos *getEsf();
private:
    Enemigos *esf;
    float escala;
};

#endif // ENEMIGOSGRAF_H
