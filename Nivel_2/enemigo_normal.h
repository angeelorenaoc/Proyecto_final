#ifndef ENEMIGO_NORMAL_H
#define ENEMIGO_NORMAL_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class Enemigo_normal: public QObject, public QGraphicsItem
{
    int PX,PY;
    int Vel=3;
    int r=10;
    int ancho=95,alto=50;
    int columnas;
    QPixmap *pixmap;
    QTimer *timer;

public:
    Enemigo_normal(QObject *parent = nullptr);

    QRectF boundingRect() const;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move();

    int getPX() const;
    int getPY() const;
    void setPX(int value);
    void setPY(int value);

public slots:
    void Actualizar();
};
#endif // ENEMIGO_NORMAL_H
