#ifndef ENEMIGO_FISICA_H
#define ENEMIGO_FISICA_H

#include <QObject>
#include <math.h>
#include <cmath>

/*Fisica para los enemigo saltarines del nivel 2 y el enemigo del nivel 3*/

class Enemigo_fisica: public QObject
{
    Q_OBJECT
    float px;
    float py;
    float masa;
    float r;
    float vx;
    float vy;
    float angulo;
    float ax;
    float ay;
    float g; //Gravedad
    float K; //Resistencia del aire
    float e; //Coeficiente de restitución
    float v; //vector velocidad
    float dt; //Delta de tiempo
    float rr; //Radio alternativo para la colision con los muros

public:
    Enemigo_fisica(float posx_, float posy_, float velx_, float vely_,float masa_, float radio_, float k_, float e_, float rr_);
    ~Enemigo_fisica();

    void Actualizar(); //Actualiza el movimiento

    void set_vel(float vx_,float vy_, float px_,float py_);
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
    float getMasa() const;
    float getR() const;
    float getVx() const;
    float getVy() const;
    float getE() const;
    float getRr() const;
};

#endif // ENEMIGO_FISICA_H
