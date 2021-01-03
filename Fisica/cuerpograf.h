#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QObject>
#include "cuerpo.h"
#include <time.h>
#include <QTimer>
#include <QPixmap>

class Cuerpograf: public QObject, public QGraphicsItem
{
public:
    explicit Cuerpograf(QObject *parent = nullptr);
    ~Cuerpograf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Cuerpo *getEsf();
    QTimer *timermo;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    void setColumnas(float value);
    void setFilas(float value);

private:
    float filas,columnas;
    float ancho;
    float alto;
    Cuerpo *esf;
    float escala;

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // CUERPOGRAF_H
