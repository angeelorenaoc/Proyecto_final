#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class personaje: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=3;
    int r=20;

//    int columnas,filas;
//    QTimer *timer;
//    QPixmap *pixmap;

    Q_OBJECT
public:
    personaje();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void setPosx(float value);
    void setPosy(float value);
    float getPosx() const;
    float getPosy() const;
    int getR() const;

//public slots:
//    void Actualizar_sprite();
};

#endif // PERSONAJE_H
