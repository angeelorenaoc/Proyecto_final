#ifndef ANUNCIO_H
#define ANUNCIO_H

#include <QGraphicsTextItem>
#include <QFont>

/*
Esta clase esta diseñada con el objetivo de mostrar al jugador
diferentes datos de interes en la pantalla, como lo son la vida,
la velocidad(en caso del nivel 2) y el puntaje.
*/

class Anuncio: public QGraphicsTextItem
{
    //************* Datos ****************************************************************************
    int anuncio; //Vida, puntaje o velocidad segun sea el caso
    int Px, Py; //Posicion en la pantalla
    int color, id, nivel; //Color del texto, identificador que permite variar la informacion a mostrar
    //*************************************************************************************************

public:
    Anuncio(QGraphicsItem * parent=0, int colorp=0, int id_=0,int tamanio=15, int nivel_=1);

    void decrease_vida(int i);
    void increse_score(int i);

    int getAnuncio() const;
    void setAnuncio(int value);

    int getPx() const;
    void setPx(int value);

    int getPy() const;
    void setPy(int value);
};

#endif // ANUNCIO_H
