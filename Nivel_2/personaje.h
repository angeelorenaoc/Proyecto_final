#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
#include <QTimer>
#include <QPainter>

class Personaje: public QGraphicsItem, public QObject
{
    int PX, PY;
    int columnas,filas;
    int ancho=100, alto=100;
    QPixmap *pixmap;
    QTimer *timer;

    int angulo;
    int vel_inicial;

public:
    Personaje(QObject *parent = nullptr,int _px=0, int _py=0,int fil=0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    void disparo();

    void up();
    void down();
    void left();
    void right();

    int getPX() const;
    int getPY() const;
    int getAngulo() const;
    int getVel_inicial() const;

    int getFilas() const;
    void setFilas(int value);
    int getColumnas() const;
    void setColumnas(int value);

public slots:
    void Actualizar();
};
#endif // PERSONAJE_H
