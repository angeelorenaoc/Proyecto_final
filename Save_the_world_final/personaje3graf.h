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

/* Es clase maneja todo lo referente a la imagen de los
 * personajes con movientos fisicos.*/

class Personaje3graf: public QObject, public QGraphicsItem
{
public:
    explicit Personaje3graf(QObject *parent = nullptr, int id = 0);
    ~Personaje3graf();

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void actualizar (float v_limit);
    void setColumnas(float value);
    void setFilas(float value);
    float getAlto() const;
    float getAncho() const;

    Personaje3 *getEsf();

private:
    float filas,columnas;
    float ancho;
    float alto;

    QTimer *timermo;
    QPixmap *pixmap;
    Personaje3 *esf;

signals:

public slots:
    //Actualiza el sprite.
    void Actualizacion();
};

#endif // PERSONAJE3GRAF_H
