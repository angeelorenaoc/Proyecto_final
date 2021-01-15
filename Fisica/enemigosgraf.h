#ifndef ENEMIGOSGRAF_H
#define ENEMIGOSGRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QObject>
#include "enemigos.h"
#include <QTimer>
#include <QPixmap>

class Enemigosgraf: public QObject, public QGraphicsItem
{
public:
    explicit Enemigosgraf(QObject *parent = nullptr);
    ~Enemigosgraf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Enemigos *getEsf();
    QTimer *timerm;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    void setFilas(float value);
    void setColumnas(float value);
    float getAncho() const;

private:
    float filas,columnas;
    float ancho;
    float alto;
    Enemigos *esf;
    float escala;

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // ENEMIGOSGRAF_H
