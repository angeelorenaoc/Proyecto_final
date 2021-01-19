#include "anuncio.h"

Anuncio::Anuncio(QGraphicsItem *parent, int colorp, int id_,int tamanio, int nivel_)
{
    color = colorp;
    id = id_;/* Variable que permite identificar el tipo de anuncio. Si id = 0
               se refiere a la vida; si id = 1, es el puntaje; y si id = 2, es la
               velocidad.*/
    nivel = nivel_;// Variable que permite identificar el nivel

    if(nivel != 2){
        if (id == 0 ){
            anuncio = 3;
            setPlainText(QString("Vida: ")+ QString::number(anuncio));}
        else if ( id == 1){
            anuncio = 0;
            setPlainText(QString("Puntaje: ")+ QString::number(anuncio));}
    }
    else {
        anuncio = 10;
        pixmap = new QPixmap(":/new/Imagenes/sprite_Vida.png");
        setScale(0.85);
        columnas = 0;
        setPos(Px,Py);
        if (id == 1){
            anuncio = 0;
            setPlainText(QString("Puntaje: ")+ QString::number(anuncio));}
        else if (id == 2){
            anuncio = 0;
            setPlainText(QString("Velocidad: ")+ QString::number(anuncio));}
    }
    if(color == 0)
        setDefaultTextColor(Qt::blue);
    else
        setDefaultTextColor(Qt::magenta);

    setFont(QFont("Tekton Pro",tamanio));
    setPos(Px,Py);
}

QRectF Anuncio::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Anuncio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (nivel == 2 && id == 0){
        /*El sprite de la vida solo se invoca en el nivel 2*/
        painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);}
}


void Anuncio::decrease_vida(int i)//Metodo que permite decrementar i veces el numero de vidas
{
    anuncio-=i;
    if (nivel != 2)
        setPlainText(QString("Vida: ")+QString::number(anuncio));
    else{
        /*Permite recorrer el sprite evitando la situacion de cuando columnas toma
        valores inexistentes en la imagen*/
        if(columnas<=1431 && i==2){
            columnas+=159*i;
        }
        else if(columnas < 1749){
            columnas+=159;
        }
        this->update(-ancho/2,-alto/2,ancho,alto);
    }
}

void Anuncio::increse_score(int i)//Metodo que permite aumentar i veces el puntaje
{
    anuncio+=i;
    if (id == 1) {
        setPlainText(QString("Puntaje: ")+ QString::number(anuncio));
        setFont(QFont("times",16));
    }
    else if (id == 2){
        setPlainText(QString("Velocidad: ")+ QString::number(anuncio));
        setFont(QFont("times",10));
    }
}

int Anuncio::getPx() const
{
    return Px;
}

void Anuncio::setPx(int value)
{
    Px = value;
}

int Anuncio::getPy() const
{
    return Py;
}

void Anuncio::setPy(int value)
{
    Py = value;
}

int Anuncio::getAnuncio() const
{
    return anuncio;
}

void Anuncio::setAnuncio(int value)
{
    anuncio = value;
}
