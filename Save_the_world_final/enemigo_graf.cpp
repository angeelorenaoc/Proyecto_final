#include "enemigo_graf.h"

Enemigo_graf::Enemigo_graf(QObject *parent, int nivel_) : QObject(parent)
{
    float posx,posy,velx,vely,masa,r,K,e,rr;
    nivel = nivel_;

    // Se definen valores por defecto dependiendo del nivel
    if (nivel==3){
        pixmap = new QPixmap(":/new/Imagenes/Enemigo_3.png");

        ancho = 45;
        alto  = 80;
        columnas = 0;

        posx = 32;
        posy = 30;
        r = 40;
        masa = 50;
        velx = 0;
        vely = 0;
        K = 0.08;
        e = 0.09;
        rr = 1;
    }
    else{
        columnas = 1200;
        pixmap = new QPixmap(":/new/Imagenes/Lenador_saltando.png");
        setScale(0.7);
        ancho=43;
        alto=62;

        posx = 800;
        posy = 0;
        r = 20;
        masa = 50;
        velx = -10;
        vely = 0;
        K = 0.08;
        e = 0.09;
        rr = 10;
    }

    setPos(posx,posy);

    //Se crea una instacia de la clase enemigo_fisica
    enemy = new Enemigo_fisica(posx,posy,velx,vely,masa,r,K,e,rr);

    //******************Manejo del sprite******************************
    filas = 0;
    timerm = new QTimer();
    timerm->start(100);
    connect(timerm,&QTimer::timeout,this,&Enemigo_graf::Actualizacion);
    //*****************************************************************
}

Enemigo_graf::~Enemigo_graf()
{
    delete enemy;
}

QRectF Enemigo_graf::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Enemigo_graf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void Enemigo_graf::actualizar(float v_limit)
{
    enemy->Actualizar();
    setPos(enemy->getPx(),v_limit-enemy->getPy());
}

Enemigo_fisica *Enemigo_graf::getEnemy()
{
    return enemy;
}

void Enemigo_graf::setFilas(float value)
{
    filas = value;
}

void Enemigo_graf::setColumnas(float value)
{
    columnas = value;
}

float Enemigo_graf::getAncho() const
{
    return ancho;
}

void Enemigo_graf::up()
/*Metodo usado para que el enemigo del nivel 2
 * salte con una velocidad constante, describiendo
 * un movimiento parabolido
 */
{
    enemy->set_vel(-10,100,enemy->getPx(),enemy->getPy());
}


void Enemigo_graf::Actualizacion()
{
    //Se varia entre los diferentes sprites, dependiendo el nivel
    if (nivel == 3){
        columnas += 45;
        if(columnas >= 405)
        {
            columnas =0;
        }
    }
    else{
        if(enemy->getVy()==0)
             columnas=ancho;
        else if(enemy->getVy()>0)
            columnas=0;
        else if(enemy->getVy()<0)
            columnas=ancho*2;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}
