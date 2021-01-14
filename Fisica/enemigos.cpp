#include "enemigos.h"

void Enemigos::setPx(float value)
{
    px = value;
}

void Enemigos::setPy(float value)
{
    py = value;
}

float Enemigos::getRr() const
{
    return rr;
}

Enemigos::Enemigos(float posx_, float posy_, float velx_, float vely_,float masa_, float radio_, float k_, float e_, float rr_)
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

Enemigos::~Enemigos()
{

}

void Enemigos::Actualizar()
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

float Enemigos::getE() const
{
    return e;
}

float Enemigos::getPx() const
{
    return px;
}

float Enemigos::getPy() const
{
    return py;
}

float Enemigos::getMasa() const
{
    return masa;
}

float Enemigos::getR() const
{
    return r;
}

float Enemigos::getVx() const
{
    return vx;
}

float Enemigos::getVy() const
{
    return vy;
}

void Enemigos::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}




