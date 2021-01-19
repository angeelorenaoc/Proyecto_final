#include "enemigo_fisica.h"
Enemigo_fisica::Enemigo_fisica(float posx_, float posy_, float velx_, float vely_,float masa_, float radio_, float k_, float e_, float rr_)
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
    rr = rr_;
}

Enemigo_fisica::~Enemigo_fisica()
{

}

void Enemigo_fisica::Actualizar()
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

void Enemigo_fisica::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}

float Enemigo_fisica::getPy() const
{
    return py;
}

void Enemigo_fisica::setPy(float value)
{
    py = value;
}

float Enemigo_fisica::getMasa() const
{
    return masa;
}

float Enemigo_fisica::getR() const
{
    return r;
}

float Enemigo_fisica::getVx() const
{
    return vx;
}

float Enemigo_fisica::getVy() const
{
    return vy;
}

float Enemigo_fisica::getE() const
{
    return e;
}

float Enemigo_fisica::getRr() const
{
    return rr;
}

float Enemigo_fisica::getPx() const
{
    return px;
}

void Enemigo_fisica::setPx(float value)
{
    px = value;
}
