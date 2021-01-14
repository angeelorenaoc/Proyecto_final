#ifndef BALA_COMUN_H
#define BALA_COMUN_H

#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>

class Bala_comun: public QObject, public QGraphicsItem
{
    int r = 5;
    int posx, posy;
    int sentido;
    bool collides = false;
    int id;

    Q_OBJECT
public:
    Bala_comun(int sentido_);
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getSentido() const;

    int getId() const;
    void setId(int value);

public slots:
    void move();
};

#endif // BALA_COMUN_H