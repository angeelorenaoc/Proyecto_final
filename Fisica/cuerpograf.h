#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include "cuerpo.h"
#include <time.h>

class Cuerpograf: public QGraphicsItem
{
public:
    Cuerpograf();
    ~Cuerpograf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Cuerpo *getEsf();
private:
    Cuerpo *esf;
    float escala;
};

#endif // CUERPOGRAF_H
