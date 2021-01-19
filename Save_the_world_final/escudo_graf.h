#ifndef ESCUDO_GRAF_H
#define ESCUDO_GRAF_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "escudos_fisica.h"

class escudo_graph: public QGraphicsItem
{
public:
    escudo_graph(float x, float y, float vx, float vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float dt);
    Escudos_fisica * getEsf();


private:
    Escudos_fisica *esc;

};

#endif // ESCUDO_GRAF_H
