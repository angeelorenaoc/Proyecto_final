#ifndef MONEDAS_H
#define MONEDAS_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

/*Esta clase se encarga de todo lo relacionado con los
 *  bonus que se pueden recoger a lo largo del nivel 3*/

class Monedas: public QObject, public QGraphicsItem
{
    int r=10;
    int posx, posy;

    //********Sprite***********
    int ancho = 75, alto = 70;
    int columnas;
    QPixmap *pixmap;
    QTimer *timer;
    //*************************

public:
    Monedas(int x, int y);

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
