#include "personaje3.h"

Personaje3::Personaje3(float posx_, float posy_, float velx_, float vely_, float masa_, float radio_, float k_, float e_, float rr_)
{
    // Se definen los valores por defecto para el objeto
    px =posx_;
    py = posy_;
    masa = masa_;
    vx=velx_;
    vy=vely_;
    r =radio_;
    rr = rr_;
    ax = 0;
    ay= 0;
    g = 9.8;
    e= e_;
    K= k_;
    v = 0;
    dt = 0.1;
}

Personaje3::~Personaje3()
{

}

//************************Ecuaciones de movimiento***********************
void Personaje3::Actualizar()
{
    v = pow(((vx*vx)+(vy*vy)),1/2);
    angulo = atan2(vy,vx);
    ax = -((K*(v*v)*(r*r))/masa)*cos(angulo);
    ay = (-((K*(v*v)*(r*r))/masa)*sin(angulo))-g;
    px = px +((vx*(dt))) + (((ax*(dt*dt)))/2);
    py = py +((vy*(dt))) + (((ay*(dt*dt)))/2);
    vx =vx +ax*dt;
    vy = vy +ay*dt;
}

void Personaje3::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}
//***********************************************************************

float Personaje3::getPy() const
{
    return py;
}

float Personaje3::getMasa() const
{
    return masa;
}

float Personaje3::getR() const
{
    return r;
}

float Personaje3::getVx() const
{
    return vx;
}

float Personaje3::getVy() const
{
    return vy;
}

float Personaje3::getE() const
{
    return e;
}

float Personaje3::getPx() const
{
    return px;
}

void Personaje3::setAx(float value)
{
    ax = value;
}

void Personaje3::setAy(float value)
{
    ay = value;
}

void Personaje3::setPx(float value)
{
    px = value;
}

void Personaje3::setPy(float value)
{
    py = value;
}

float Personaje3::getRr() const
{
    return rr;
}

