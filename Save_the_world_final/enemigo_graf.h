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

class Enemigo_graf: public QObject, public QGraphicsItem
{
public:
    explicit Enemigo_graf(QObject *parent = nullptr, int nivel_= 1);
    ~Enemigo_graf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Enemigo_fisica *getEnemy();
    QTimer *timerm;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    void setFilas(float value);
    void setColumnas(float value);
    float getAncho() const;
    void up();

private:
    float filas,columnas;
    float ancho;
    float alto;
    Enemigo_fisica *enemy;
    float escala;
    int nivel;

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // ENEMIGO_GRAF_H
