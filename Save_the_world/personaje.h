#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class personaje: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=3;
    int r=20;
    int angulo;
    int vel_inicial;

    int id;

    int ancho,alto;
    int columnas,filas;
    QTimer *timer;
    QPixmap *pixmap;

    Q_OBJECT
public:
    personaje(int id_);
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

    int getAngulo() const;
    int getVel_inicial() const;

public slots:
    void Actualizar_sprite();
};

#endif // PERSONAJE_H
