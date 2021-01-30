#ifndef VIDA_II_H
#define VIDA_II_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

/*
Esta clase esta diseñada con el objetivo de mostrar al jugador
a traves de un sprite la vida en el nivel 2.
*/

class Vida_II: public QGraphicsItem
{
    int vida = 10;
    int Px = 710;
    int Py = 40;

    //***********Para el manejo del sprite en el Nivel 2***************
    int ancho=159, alto=94; //Dimensiones de la imagen de la imagen
    int columnas; //Permite alternar entre las posiciones en el sprite
    QPixmap *pixmap; //Carga la imagen
    //******************************************************************
public:
    Vida_II(QGraphicsItem * parent=0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    void decrease_vida(int i);
    int getVida() const;
};

#endif // VIDA_II_H
