#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

/*
Esta clase es la encargada de manejar todo lo referente al movimiento
e imagen de los personajes que no poseen movimientos o su movimiento
es el M.R.U.
*/

class Personaje: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=5;
    int angulo;
    int vel_inicial;

    int id, nivel;

    int ancho,alto;
    int columnas,filas;
    QTimer *timer;
    QPixmap *pixmap;

    Q_OBJECT
public:
    Personaje(QObject *parent = nullptr,int id_=0, int nivel_=0, int posx_=0, int posy_=0);
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void disparo();

    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);

    int getColumnas() const;
    void setColumnas(int value);

    int getFilas() const;
    void setFilas(int value);

    int getAngulo() const;

    int getVel_inicial() const;
    void setVel_inicial(int value);

public slots:
    void Actualizar_sprite();
};

#endif // PERSONAJE_H
