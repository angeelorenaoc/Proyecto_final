#include "enemigo_normal.h"

void Enemigo_normal::setVelocidad(int value)
{
    velocidad = value;
}

Enemigo_normal::Enemigo_normal(int nivel_)
{
    nivel = nivel_;
    if (nivel == 2){
        int random_number = rand()% 400+10;
        setPos(800,random_number);
        posx=800;posy=random_number;

        columnas = 0;
        ancho = 95;
        alto = 50;
        pixmap = new QPixmap(":/Imagenes/Perro_sprite.png");
        setScale(0.8);

        timer= new QTimer;
        connect(timer,&QTimer::timeout,this,&Enemigo_normal::Actualizar_sprite);
        timer->start(50);
    }
    else{
        int random_number=rand()%3;

        if(random_number==0){
            random_number = rand()%170+135;
            setPos(21,random_number);
            setPosx(21);setPosy(random_number);
        }
        else if(random_number==1){
            random_number = rand()%619+185;
            setPos(random_number,600);
            setPosx(random_number);setPosy(600);
        }
        else{
            random_number = rand()%70+207;
            setPos(920,random_number);
            setPosx(920);setPosy(random_number);
        }
        columnas=0;
        ancho = 100;
        alto = 100;

        pixmap = new QPixmap(":/Imagenes/Covid.png");
        setScale(0.45);

        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &Enemigo_normal::Actualizar_sprite);
        timer->start(150);
    }
}

QRectF Enemigo_normal::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo_normal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-r,-r,*pixmap,columnas,0,ancho,alto);
}

void Enemigo_normal::up()
{
    posy-= velocidad;
    setPos(posx,posy);
}

void Enemigo_normal::down()
{
    posy+= velocidad;
    setPos(posx,posy);
}

void Enemigo_normal::left()
{
    posx-= velocidad;
    setPos(posx,posy);
}

void Enemigo_normal::right()
{
    posx+= velocidad;
    setPos(posx,posy);
}

float Enemigo_normal::getPosx() const
{
    return posx;
}

float Enemigo_normal::getPosy() const
{
    return posy;
}

int Enemigo_normal::getR() const
{
    return r;
}

int Enemigo_normal::getVelocidad() const
{
    return velocidad;
}

void Enemigo_normal::Actualizar_sprite()
{
    if (nivel ==1){
        columnas += 100;
        if(columnas >= 200){
            columnas = 0;
        }
    }
    else{
        columnas += 95;
        if(columnas >= 190)
        {
            columnas =0;
        }
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
void Enemigo_normal::setPosx(float value)
{
    posx = value;
}

void Enemigo_normal::setPosy(float value)
{
    posy = value;
}

