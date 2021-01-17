#include "anuncios.h"

anuncios::anuncios(QGraphicsItem *parent, int colorp, int id_,int tamanio)
{
    color = colorp;
    id = id_;

    if(id==0){
        anuncio = 3;
        setPlainText(QString("Vida: ")+ QString::number(anuncio));
    }
    else{
        anuncio = 0;
        setPlainText(QString("Puntaje: ")+ QString::number(anuncio));
    }
    if(color == 0)
        setDefaultTextColor(Qt::blue);
    else
        setDefaultTextColor(Qt::magenta);

    setFont(QFont("Tekton Pro",tamanio));
    setPos(Px,Py);
}

void anuncios::decrease_vida(int i)
{
    anuncio-=i;
    setPlainText(QString("Vida: ")+QString::number(anuncio));
}

void anuncios::increse_score(int i)
{
    anuncio+=i;
    setPlainText(QString("Puntaje: ")+QString::number(anuncio));
}

int anuncios::getAnuncio() const
{
    return anuncio;
}

void anuncios::setAnuncio(int value)
{
    anuncio = value;
}

int anuncios::getPx() const
{
    return Px;
}

int anuncios::getPy() const
{
    return Py;
}

void anuncios::setPx(int value)
{
    Px = value;
}

void anuncios::setPy(int value)
{
    Py = value;
}
