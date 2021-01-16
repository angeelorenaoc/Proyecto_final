#ifndef MONEDAS_H
#define MONEDAS_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class monedas: public QObject, public QGraphicsItem
{
    int r=10;
    int posx, posy;
    int ancho = 75, alto = 70;
    int columnas;
    QPixmap *pixmap;
    QTimer *timer;

public:
    monedas(int x, int y);

    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public slots:
    void Actualizar();

};
#endif // MONEDAS_H
