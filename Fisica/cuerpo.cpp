#include "cuerpo.h"
#include <math.h>
#include <cmath>

void Cuerpo::setAx(float value)
{
    ax = value;
}

void Cuerpo::setAy(float value)
{
    ay = value;
}

void Cuerpo::setPx(float value)
{
    px = value;
}

void Cuerpo::setPy(float value)
{
    py = value;
}

Cuerpo::Cuerpo(float posx_, float posy_, float velx_, float vely_, float masa_, float radio_, float k_, float e_)
{
    px =posx_;
    py = posy_;
    masa = masa_;
    vx=velx_;
    vy=vely_;
    r =radio_;
    ax = 0;
    ay= 0;
    g = 9.8;
    e= e_;
    K= k_;
    v = 0;
    dt = 0.1;
}

Cuerpo::~Cuerpo()
{

}

float Cuerpo::getPy() const
{
    return py;
}

float Cuerpo::getMasa() const
{
    return masa;
}

float Cuerpo::getR() const
{
    return r;
}

float Cuerpo::getVx() const
{
    return vx;
}

float Cuerpo::getVy() const
{
    return vy;
}

void Cuerpo::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}

float Cuerpo::getE() const
{
    return e;
}


void Cuerpo::Actualizar()
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

float Cuerpo::getPx() const
{
    return px;
}
