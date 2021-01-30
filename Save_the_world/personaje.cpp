#include "personaje.h"

Personaje::Personaje(QObject *parent,int id_, int nivel_,int posx_, int posy_): QObject(parent)
{
    id=id_; //Identidicador para determinar la imagen del jugador (multijugador)
    nivel = nivel_;
    columnas=0;
    filas=0;

    // Dependiendo del nivel se carga la imagen del personaje y se definen sus dimendiones
    if (nivel == 1){
        ancho = 60;
        alto = 95;
        if(id==0)
            pixmap = new QPixmap(":/new/Imagenes/Sprite_medico_1.png");
        else if (id == 1)
            pixmap = new QPixmap(":/new/Imagenes/Sprite_medico2.png");
        else if (id == 2)
            pixmap = new QPixmap(":/new/Imagenes/Sprite_medico3.png");
        else
            pixmap = new QPixmap(":/new/Imagenes/Sprite_medico4.png");

        setScale(0.6);
        timer = new QTimer();//Creacion del timer para el nivel 1
        connect(timer, &QTimer::timeout, this, &Personaje::Actualizar_sprite);
        timer->start(150);
    }
    else {
        ancho=100;
        alto=100;
        angulo=45;
        vel_inicial=0;

        timer = new QTimer();
        if(id == 0)
            filas = 0;
        else if (id == 1)
            filas = 100;
        else
            filas = 200;
        columnas = 1200;
        pixmap = new QPixmap(":/new/Imagenes/Sprite_canon.png");
        setScale(0.8);
        setRotation(45);
        timer = new QTimer();//Creacion del timer para el nivel 2
        connect(timer, &QTimer::timeout, this, &Personaje::Actualizar_sprite);
        //en este caso el timer no se inicia ya que el sprite solo se recorre cuando dispara
    }
    posx = posx_;
    posy = posy_;
    setPos(posx,posy);
}

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void Personaje::Actualizar_sprite()
{
    if (nivel == 1){
        columnas += 60;
        if(columnas >= 540){
            columnas = 0;
        }

        this->update(-ancho/2,-alto/2,ancho,alto);
    }
    else{
        columnas += 100;
        if(columnas >= 1300)
        {
            columnas =1200;
            timer->stop();
        }
        this->update(-ancho/2,-alto/2,ancho,alto);
    }
}

void Personaje::disparo()
{
    columnas=0;
    timer->start(100);
}

//*************************************************
/* En el caso del nivel 1 se mueve al personaje por
 * la pantalla, en caso del nivel 2 se modifica el
 * angulo y la velocidad inicial de disparo. */
void Personaje::up()
{
    if (nivel == 1){
        posy-= velocidad;
        filas=95;
        setPos(posx,posy);
    }
    else{
        angulo+=5;
        setRotation(90-angulo);
    }
}

void Personaje::down()
{
    if (nivel == 1){
        posy+= velocidad;
        filas=0;
        setPos(posx,posy);
    }
    else{
        angulo-=5;
        setRotation(90-angulo);
    }
}

void Personaje::left()
{
    if (nivel == 1){
        posx-= velocidad;
        filas=285;
        setPos(posx,posy);
    }
    else{
       vel_inicial-=5;
    }
}

void Personaje::right()
{
    if (nivel == 1){
        posx+= velocidad;
        filas=190;
        setPos(posx,posy);
    }
    else{
        vel_inicial+=5;
    }
}
//************************************************

float Personaje::getPosy() const
{
    return posy;
}

void Personaje::setPosy(float value)
{
    posy = value;
}

float Personaje::getPosx() const
{
    return posx;
}

void Personaje::setPosx(float value)
{
    posx = value;
}

int Personaje::getColumnas() const
{
    return columnas;
}

void Personaje::setColumnas(int value)
{
    columnas = value;
}

int Personaje::getFilas() const
{
    return filas;
}

void Personaje::setFilas(int value)
{
    filas = value;
}

int Personaje::getAngulo() const
{
    return angulo;
}

int Personaje::getVel_inicial() const
{
    return vel_inicial;
}

void Personaje::setVel_inicial(int value)
{
    vel_inicial = value;
}
