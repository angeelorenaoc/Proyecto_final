#ifndef ANUNCIOS_H
#define ANUNCIOS_H

#include <QGraphicsTextItem>
#include <QFont>

class anuncios: public QGraphicsTextItem
{    
    int anuncio;
    int Px, Py;
    int color, id;

public:
    anuncios(QGraphicsItem * parent=0, int colorp=0, int id_=0,int tamanio=15);
    void decrease_vida(int i);
    void increse_score(int i);

    int getPx() const;
    int getPy() const;

    void setPx(int value);
    void setPy(int value);

    int getAnuncio() const;
    void setAnuncio(int value);
};

#endif // ANUNCIOS_H
