#ifndef ENEMIGOS_SGRAPH_H
#define ENEMIGOS_SGRAPH_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include "enemigos_saltarines.h"
#include <QTimer>
#include <QPixmap>
#include <QDebug>

class Enemigos_sGraph: public QObject, public QGraphicsItem
{
public:
    Enemigos_sGraph();
    ~Enemigos_sGraph();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    Enemigos_saltarines *getEnemy() const;
    void up();
    void actualizar(float v_limit);

private:
    Enemigos_saltarines *enemy;

};

#endif // ENEMIGOS_SGRAPH_H
