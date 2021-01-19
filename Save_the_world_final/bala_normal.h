#ifndef BALA_NORMAL_H
#define BALA_NORMAL_H

#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Bala_normal: public QObject, public QGraphicsItem
{
    int posx, posy;
    int sentido;
    bool collides = false;
    int id;

    int ancho, alto;
    QPixmap *pixmap;

    Q_OBJECT
public:
    Bala_normal(int sentido_);
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getSentido() const;

    int getId() const;
    void setId(int value);

public slots:
    void move();
};

#endif // BALA_NORMAL_H
