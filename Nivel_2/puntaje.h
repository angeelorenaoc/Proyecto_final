#ifndef Puntaje_H
#define Puntaje_H

#include <QGraphicsTextItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem * parent = 0, int colorp = 0,int id=0);
    void increase(int s);
    void up_vel();
    int getPuntaje();
    void setScore(int value);
    void setColor(int value);

private:
    int score;
    int color;
    int id;
};

#endif // Puntaje_H
