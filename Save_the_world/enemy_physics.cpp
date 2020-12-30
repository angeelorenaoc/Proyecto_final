#include "enemy_physics.h"

enemy_physics::enemy_physics(float posx_, float posy_, float Velx_, float Vely_,float masa_, float radio_, float k_, float e_)
{
    PX =posx_;
    PY = posy_;
    mass = masa_;
    VX=Velx_;
    VY=Vely_;
    R =radio_;
    AX = 0;
    AY= 0;
    G = 9.8;
    e= e_;
    K= k_;
    V = 0;
    dt = 0.1;
}

enemy_physics::~enemy_physics()
{

}

void enemy_physics::Actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
    //angulo = atan2(VY,VX);
    AX = -((K*(V*V)*(R*R))/mass);//*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass));//*sin(angulo))-G;
    PX = PX +((VX*(dt))) + (((AX*(dt*dt)))/2);
    PY = PY +((VY*(dt))) + (((AY*(dt*dt)))/2);
    VX =VX +AX*dt;
    VY = VY +AY*dt;
}

float enemy_physics::getE() const
{
    return e;
}

float enemy_physics::getPX() const
{
    return PX;
}

float enemy_physics::getPY() const
{
    return PY;
}

float enemy_physics::getMasa() const
{
    return mass;
}

float enemy_physics::getR() const
{
    return R;
}

float enemy_physics::getVX() const
{
    return VX;
}

float enemy_physics::getVY() const
{
    return VY;
}

void enemy_physics::setPX(float Value)
{
    PX = Value;
}

void enemy_physics::setPY(float Value)
{
    PY = Value;
}

void enemy_physics::set_vel(float Vx_, float Vy_, float px_, float py_)
{
    VX = Vx_;
    VY = Vy_;
    PX = px_;
    PY= py_;
}
