#ifndef ENEMIGO_GRAF_H
#define ENEMIGO_GRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include "enemigo_fisica.h"

/* Es clase maneja todo lo referente a la imagen de los
 * enemigos con movientos fisicos.
 */

class Enemigo_graf: public QObject, public QGraphicsItem
{
public:
    explicit Enemigo_graf(QObject *parent = nullptr, int nivel_= 1);
    ~Enemigo_graf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    //******Metodos encargados del movimiento****
    void actualizar (float v_limit);
    void up();
    //*******************************************

    Enemigo_fisica *getEnemy();

    void setFilas(float value);
    void setColumnas(float value);
    void setescala (float s);
    float getAncho() const;

private:
    int nivel;
    float filas,columnas;
    float ancho, alto;
    Enemigo_fisica *enemy;
    QTimer *timerm;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // ENEMIGO_GRAF_H
