#ifndef puntaje_H
#define puntaje_H

#include <QGraphicsTextItem>
#include <QFont>

class puntaje: public QGraphicsTextItem
{
public:
    puntaje(QGraphicsItem * parent = 0, int colorp = 0);
    void increase();
    void increse_low();
    int getpuntaje();
    void setScore(int value);
    void setColor(int value);

private:
    int score;
    int color;
};

#endif // puntaje_H
