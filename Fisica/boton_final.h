#ifndef BOTON_FINAL_H
#define BOTON_FINAL_H
#include <QGraphicsTextItem>
#include <QObject>


class Boton_final : public QGraphicsTextItem, public QObject
{
public:
    explicit Boton_final(QObject *parent = nullptr);
private:
    int px;
    int py;
};

#endif // BOTON_FINAL_H
