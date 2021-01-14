#include "bala.h"

Bala::Bala(float posx_, float posy_,float masa_, float radio_, float k_, float e_,float a_,float v_)
{
    px =posx_;
    py = posy_;
    angulo = a_;
    v = v_;
    masa = masa_;
    vx=0;
    vy=0;
    r =radio_;
    ax = 0;
    ay= 0;
    g = 9.8;
    e= e_;
    K= k_;
    dt = 0.1;
}

void Bala::setPx(float value)
{
    px = value;
}

void Bala::setPy(float value)
{
    py = value;
}


Bala::~Bala()
{

}

void Bala::ActualizarPosicion()
{
    CalcularVelocidad();
    px=px+vx*dt;
    py=py+vy*dt-(0.5*g*dt+dt);
}

void Bala::CalcularVelocidad()
{
    vx=v*cos(angulo);
    vy=v*sin(angulo)-g*dt;
    angulo=atan2(vy,vx);
    v=sqrt(pow(vy,2)+pow(vx,2));
}

float Bala::getE() const
{
    return e;
}

float Bala::getPx() const
{
    return px;
}

float Bala::getPy() const
{
    return py;
}

float Bala::getMasa() const
{
    return masa;
}

float Bala::getR() const
{
    return r;
}

float Bala::getVx() const
{
    return vx;
}

float Bala::getVy() const
{
    return vy;
}

void Bala::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}
