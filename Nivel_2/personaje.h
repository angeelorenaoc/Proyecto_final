#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class Personaje: public QGraphicsItem
{
    int PX, PY;
    int columnas;
    int ancho, alto;

    int angulo;
    int vel_inicial;

public:
    Personaje(int _px, int _py);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    void up();
    void down();

    void left();
    void right();

    int getPX() const;
    int getPY() const;
    int getAngulo() const;
    int getVel_inicial() const;
};

#endif // PERSONAJE_H
