#ifndef ESCUDO_H
#define ESCUDO_H

#include <math.h>
#include <cmath>

class escudo
{
private:
    float PX;
    float PY;
    float VX;
    float VY;
    float Distancia;
    float masa = 100;
    float AX;
    float AY;
    float G;
    float R = 5;

public:
    escudo(float px_, float py_, float vx_, float vy_);

    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;

    void acelerar(float px2_, float py2_, float masa2);
    void actualizar(float dt);
    void setMasa(float value);
};
#endif // ESCUDO_H
