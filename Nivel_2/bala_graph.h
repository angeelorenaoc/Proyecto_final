#ifndef BALA_GRAPH_H
#define BALA_GRAPH_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include "bala.h"
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class Bala_graph: public QObject, public QGraphicsItem
{
public:
    Bala_graph(float px, float py,float ang,float v);
    ~Bala_graph();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float v_limit);
    Bala *getBala() const;
    int getId() const;
    void setId(int value);

private:
    Bala *bala;
    int id;

};

//signals:

//public slots:
//    void move();

#endif // BALA_GRAPH_H
