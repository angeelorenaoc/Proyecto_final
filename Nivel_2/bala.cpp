#include "bala.h"

Bala::Bala(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang=a;
}

void Bala::ActualizarPosicion()
{
    CalcularVelocidad();
    posx=posx+vel_x*tiempo;
    posy=posy+vel_y*tiempo-(0.5*g*tiempo+tiempo);
}

void Bala::CalcularVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*tiempo;
    ang=atan2(vel_y,vel_x);
    vel=sqrt(pow(vel_y,2)+pow(vel_x,2));
}

void Bala::setPosx(double value)
{
    posx = value;
}

void Bala::setPosy(double value)
{
    posy = value;
}

double Bala::getPosx() const
{
    return posx;
}

double Bala::getPosy() const
{
    return posy;
}

