#ifndef ENEMIGO_NORMAL_H
#define ENEMIGO_NORMAL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class Enemigo_normal: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=2;
    int r=20;
    int nivel;

    int columnas;
    int ancho, alto;
    QTimer *timer;
    QPixmap *pixmap;

    Q_OBJECT
public:
    Enemigo_normal(int nivel_);
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    float getPosx() const;
    void setPosx(float value);

    float getPosy() const;
    void setPosy(float value);

    int getVelocidad() const;
    void setVelocidad(int value);

    int getR() const;

public slots:
    void Actualizar_sprite();

};

#endif // ENEMIGO_NORMAL_H
