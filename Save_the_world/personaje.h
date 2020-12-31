#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class personaje: public QObject, public QGraphicsItem
{
    int posx ,posy;
    int velocidad=3;
    int r=20;

    Q_OBJECT
public:
    personaje();
    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void up();
    void down();
    void left();
    void right();

    void setPosx(int value);
    void setPosy(int value);
    int getPosx() const;
    int getPosy() const;
    int getR() const;
};

#endif // PERSONAJE_H
