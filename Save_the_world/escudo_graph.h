#ifndef ESCUDO_GRAPH_H
#define ESCUDO_GRAPH_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "escudo.h"

class escudo_graph: public QGraphicsItem
{
public:
    escudo_graph(float x, float y, float vx, float vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float dt);
    escudo* getEsf();
private:
    escudo *esc;

};
#endif // ESCUDO_GRAPH_H
