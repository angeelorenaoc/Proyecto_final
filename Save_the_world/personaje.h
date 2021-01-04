#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class personaje: public QObject, public QGraphicsItem
{
    float posx ,posy;
    int velocidad=3;
    int r=15;

    Q_OBJECT
public:
    personaje();
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
};

#endif // PERSONAJE_H
