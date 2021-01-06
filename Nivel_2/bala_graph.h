#ifndef BALA_GRAPH_H
#define BALA_GRAPH_H

#include "bala.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>

class Bala_graph :public QGraphicsItem, public QObject
{
    Bala *bala;
    QTimer *timer;

public:
    Bala_graph(double x, double y,double v, double a);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    Bala *getBala() const;

private slots:
    void Actualizar();
};

#endif // BALA_GRAPH_H
