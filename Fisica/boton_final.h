#ifndef BOTON_FINAL_H
#define BOTON_FINAL_H
#include <QGraphicsTextItem>
#include <QObject>
#include <QPixmap>
#include <QPainter>

class Boton_final : public QGraphicsTextItem, public QObject
{
public:
    explicit Boton_final(QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    int px;
    int py;
    float ancho;
    float alto;
};

#endif // BOTON_FINAL_H
