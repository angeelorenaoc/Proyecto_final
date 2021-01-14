#ifndef Puntaje_H
#define Puntaje_H
#include <QGraphicsTextItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem * parent = 0, int colorp = 0);
    void increase();
    int getPuntaje();
    void setScore(int value);
    void setColor(int value);

private:
    int score;
    int color;
};
#endif // Puntaje_H
