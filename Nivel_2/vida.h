#ifndef VIDA_H
#define VIDA_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QPixmap>
#include <QPainter>

class Vida: public QGraphicsTextItem
{
    int vida;
    int Px, Py;
    int ancho=159, alto=94;
    int columnas;
    QPixmap *pixmap;
public:
    Vida(QGraphicsItem * parent=0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    void decrease_vida(int p);

    int getVida() const;

    int getPx() const;
    int getPy() const;

    void setPx(int value);
    void setPy(int value);

};

#endif // VIDA_H
