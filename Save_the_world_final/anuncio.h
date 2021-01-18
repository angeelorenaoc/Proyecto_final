#ifndef ANUNCIO_H
#define ANUNCIO_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QPixmap>
#include <QPainter>

class Anuncio: public QGraphicsTextItem
{
    int anuncio;
    int Px, Py;
    int color, id, nivel;
    int ancho=159, alto=94;
    int columnas;
    QPixmap *pixmap;

public:
    Anuncio(QGraphicsItem * parent=0, int colorp=0, int id_=0,int tamanio=15, int nivel_=1);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void decrease_vida(int i);
    void increse_score(int i);

    int getAnuncio() const;
    void setAnuncio(int value);

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);
};

#endif // ANUNCIO_H
