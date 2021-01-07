#ifndef BALA_GRAPH_H
#define BALA_GRAPH_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include "bala.h"

class Bala_graph: public QObject, public QGraphicsItem
{
//    Q_OBJECT
public:
    Bala_graph(int px_, int py_, int v_, int a_);
    ~Bala_graph();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Bala *getBala() const;

    void move();

private:
    int posx, posy;
    int angulo;
    int vel;
    int ancho,alto;
    Bala *bala;
    QTimer *timer;

//public slots:
//    void move();
};

#endif // BALA_GRAPH_H
