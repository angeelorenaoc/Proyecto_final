#include "personaje_physics.h"

#include <math.h>
#include <cmath>

personaje_physics::personaje_physics(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_; //pos en x
    PY = posY_; //pos en y
    mass = masa_; // masa del personaje_physics
    R = radio_; //radio del personaje_physics
    VX = velX_; //vel en x
    VY = velY_; //vel en y
    AX = 0; //acel en x
    AY = 0; //acel en y
    G = 10; //gravedad
    K = K_; //Resistencia del aire
    e = e_; //Coeficiente de restitucion
    V = 0; //vector de velocidad
    dt = 0.1; //delta tiempo
}

personaje_physics::~personaje_physics()
{

}

void personaje_physics::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),(1/2));
    //angulo = atan2(VY,VX);
    AX = -((K*(V*V)*(R*R))/mass);//*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass));//*sin(angulo)-G;
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2);
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}

float personaje_physics::getPY() const
{
    return PY;
}

float personaje_physics::getMass() const
{
    return mass;
}

float personaje_physics::getR() const
{
    return R;
}

float personaje_physics::getVX() const
{
    return VX;
}

float personaje_physics::getVY() const
{
    return VY;
}

float personaje_physics::getE() const
{
    return e;
}

float personaje_physics::getPX() const
{
    return PX;
}

void personaje_physics::set_vel(float vx, float vy, float px, float py)
{
    VX = vx;
    VY = vy;
    PX = px;
    PY = py;
}
