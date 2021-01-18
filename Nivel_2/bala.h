#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <math.h>
#include <cmath>
#include <QDebug>

class Bala: public QObject
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
    float g;
    float K; //Resistencia del aire
    float e; //Coeficiente de restitución
    float v; //vector velocidad
    float dt;
public:
    Bala(float posx_, float posy_,float masa_, float radio_, float k_, float e_,float a_,float v_);
    ~Bala();
    void ActualizarPosicion();
    void CalcularVelocidad();
    float getPx() const;
    float getPy() const;
    float getMasa() const;
    float getR() const;
    float getVx() const;
    float getVy() const;
    void set_vel(float vx_,float vy_, float px_,float py_);
    float getE() const;
    void setPx(float value);
    void setPy(float value);

};

#endif // BALA_H
