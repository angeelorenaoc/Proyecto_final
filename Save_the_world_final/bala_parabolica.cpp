#include "bala_parabolica.h"
#define pi 3.1416

Bala_parabolica::Bala_parabolica(float posx_, float posy_,float masa_, float radio_, float k_, float e_,float a_,float v_)
{
    // Asignacion de los valores por defecto.
    px =posx_;
    py = posy_;
    angulo = (a_*pi)/180;
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

void Bala_parabolica::setPx(float value)
{
    px = value;
}

void Bala_parabolica::setPy(float value)
{
    py = value;
}


Bala_parabolica::~Bala_parabolica()
{

}

//*******Ecuaciones de movimiento parabolico********
void Bala_parabolica::ActualizarPosicion()
{
    CalcularVelocidad();
    px=px+vx*dt;
    py=py+vy*dt-(0.5*g*dt+dt);
}

void Bala_parabolica::CalcularVelocidad()
{
    vx=v*cos(angulo);
    vy=v*sin(angulo)-g*dt;
    angulo=atan2(vy,vx);
    v=sqrt(pow(vy,2)+pow(vx,2));
}

void Bala_parabolica::set_vel(float vx_, float vy_, float px_, float py_)
{
    vx = vx_;
    vy = vy_;
    px = px_;
    py= py_;
}
//**************************************************

float Bala_parabolica::getE() const
{
    return e;
}

float Bala_parabolica::getPx() const
{
    return px;
}

float Bala_parabolica::getPy() const
{
    return py;
}

float Bala_parabolica::getMasa() const
{
    return masa;
}

float Bala_parabolica::getR() const
{
    return r;
}

float Bala_parabolica::getVx() const
{
    return vx;
}

float Bala_parabolica::getVy() const
{
    return vy;
}
