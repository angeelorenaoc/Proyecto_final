#ifndef PERSONAJE3GRAF_H
#define PERSONAJE3GRAF_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QObject>
#include <time.h>
#include <QTimer>
#include <QPixmap>

#include <personaje3.h>

class Personaje3graf: public QObject, public QGraphicsItem
{
public:
    explicit Personaje3graf(QObject *parent = nullptr, int id = 0);
    ~Personaje3graf();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setescala (float s);
    void actualizar (float v_limit);
    Personaje3 *getEsf();
    QTimer *timermo;      //Variable para lograr que el pacman se vea comiendo
    QPixmap *pixmap;
    void setColumnas(float value);
    void setFilas(float value);
    float getAlto() const;
    float getAncho() const;

private:
    float filas,columnas;
    float ancho;
    float alto;
    Personaje3 *esf;
    float escala;

signals:

public slots:
    //Actualiza las imagenes.
    void Actualizacion();
};

#endif // PERSONAJE3GRAF_H
