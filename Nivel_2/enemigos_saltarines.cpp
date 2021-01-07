#include "enemigos_saltarines.h"

Enemigos_saltarines::Enemigos_saltarines(float posx_, float posy_, float velx_, float vely_,float masa_, float radio_, float k_, float e_, float rr_)
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

void Enemigos_saltarines::setPx(float value)
{
    px = value;
}

void Enemigos_saltarines::setPy(float value)
{
    py = value;
}

float Enemigos_saltarines::getRr() const
{
    return rr;
}

Enemigos_saltarines::~Enemigos_saltarines()
{

}

void Enemigos_saltarines::Actualizar()
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

float Enemigos_saltarines::getE() const
{
    return e;
}

float Enemigos_saltarines::getPx() const
{
    return px;
}

float Enemigos_saltarines::getPy() const
{
    return py;
}

float Enemigos_saltarines::getMasa() const
{
    return masa;
}

float Enemigos_saltarines::getR() const
{
    return r;
}

float Enemigos_saltarines::getVx() const
{
    return vx;
}

float Enemigos_saltarines::getVy() const
{
    return vy;
}

void Enemigos_saltarines::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}




