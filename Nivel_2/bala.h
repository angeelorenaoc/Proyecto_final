#ifndef BALA_H
#define BALA_H

#include <math.h>

class Bala
{
    double posx;
    double posy;
    double vel;
    double ang;
    double vel_x;
    double vel_y;
    const double tiempo=0.01;
    const double g=9.8;
    const int r=10;


public:
    Bala();
    Bala(double x, double y,double v, double a);
    double getPosy() const;
    void setPosy(double value);
    double getPosx() const;
    void setPosx(double value);
    void ActualizarPosicion();
    void CalcularVelocidad();

};
#endif // BALA_H
