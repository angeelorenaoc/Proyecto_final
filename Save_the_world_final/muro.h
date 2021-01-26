#ifndef MURO_H
#define MURO_H

#include <QGraphicsItem>
#include <QPainter>

/* Esta clase se encarga de crear los muros que aparecen en los
 * niveles 1 y 3. */

class Muro: public QGraphicsItem, public QObject
{

    int w,h; //Ancho y alto del muro
    int posx, posy;
    int  id; //Determina el tipo de muro

public:
    Muro(int w_, int h_, int x, int y, int id_,QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getW() const;
    int getH() const;
    int getPosx() const;
    int getPosy() const;
};

#endif // MURO_H
