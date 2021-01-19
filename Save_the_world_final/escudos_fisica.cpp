#include "escudos_fisica.h"
void Escudos_fisica::setMasa(float value)
{
    masa = value;
}

Escudos_fisica::Escudos_fisica(float px_, float py_, float vx_, float vy_)
{
   PX = px_;
   PY = py_;
   VX = vx_;
   VY = vy_;
   AX = 0;
   AY = 0;
   G = 6.67384*(pow(10,-11));

}

void Escudos_fisica::acelerar(float px2_, float py2_, float masa2)
{
    Distancia = pow((pow((px2_-PX),2)+pow((py2_-PY),2)),1/2);
    AX = G*masa2*(px2_-PX)/pow(Distancia,2);
    AY = G*masa2*(py2_-PY)/pow(Distancia,2);
}

void Escudos_fisica::actualizar(float dt)
{
    PX = PX + (VX*dt) + ((AX*dt*dt)/2);
    PY = PY + (VY*dt) + ((AX*dt*dt)/2);
    VX = VX + (AX*dt);
    VY = VY + (AY*dt);
}

float Escudos_fisica::getPX() const
{
    return PX;
}

float Escudos_fisica::getPY() const
{
    return PY;
}

float Escudos_fisica::getMasa() const
{
    return masa;
}

float Escudos_fisica::getR() const
{
    return R;
}
