#ifndef BALA_PARABOLICA_GRAF_H
#define BALA_PARABOLICA_GRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QDebug>
#include "bala_parabolica.h"

/* Es clase maneja todo lo referente a la imagen de la
 * bala parabolica.
 */

class Bala_parabolica_graf: public QObject, public QGraphicsItem
{
public:
    Bala_parabolica_graf(float px, float py,float ang,float v);
    ~Bala_parabolica_graf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void actualizar(float v_limit);
    int getId() const;
    void setId(int value);

    Bala_parabolica *getBala() const;

private:    
    Bala_parabolica *bala;

    int id;

    //****Sprite****
    QPixmap *pixmap;
    int r_sprite=64;
    //**************

};

#endif // BALA_PARABOLICA_GRAF_H
