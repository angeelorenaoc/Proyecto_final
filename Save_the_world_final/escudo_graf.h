#ifndef ESCUDO_GRAF_H
#define ESCUDO_GRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "escudos_fisica.h"

/* Ests clase tiene el objetivo de graficar
 * el escudo del jugador
 */
class escudo_graf: public QGraphicsItem
{
public:
    escudo_graf(float x, float y, float vx, float vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    Escudos_fisica * getEsf();

    //Posicion en la pantalla
    void actualizar(float dt);

private:
    Escudos_fisica *esc;

};

#endif // ESCUDO_GRAF_H
