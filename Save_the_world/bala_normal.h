#ifndef BALA_NORMAL_H
#define BALA_NORMAL_H

#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

/*
Esta clase es la encargada de manejar todo lo referente al movimiento
e imagen de las balas que no poseen movimientos fisicos diferentes del
M.R.U.
*/

class Bala_normal: public QObject, public QGraphicsItem
{
    //*********************Atributos****************************************
    int posx, posy; //Posicion en la pantalla
    int sentido; //Determina la direccion con la que la bala saldra disparada
    int id; //Variable que identifica que jugador la disparo
    //**********************************************************************

    //***Manejo de sprite***
    int ancho, alto;
    QPixmap *pixmap;
    //**********************

    Q_OBJECT
public:
    Bala_normal(int sentido_);
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getSentido() const;

    int getId() const;
    void setId(int value);

public slots:
    void move(); //Mueve la bala
};

#endif // BALA_NORMAL_H
