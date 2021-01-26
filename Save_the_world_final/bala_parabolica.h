#ifndef BALA_PARABOLICA_H
#define BALA_PARABOLICA_H
#include <QObject>
#include <math.h>
#include <cmath>
#include <QDebug>

/*
Esta clase es la encargada de manejar todo lo referente al movimiento
de las balas que poseen movimientos fisicos diferentes al M.R.U.
*/

class Bala_parabolica: public QObject
{
    Q_OBJECT
    float px;
    float py;
    float masa;
    float r; //Radio
    float vx;
    float vy;
    float angulo;
    float ax;
    float ay;
    float g; //Gravedad
    float K; //Resistencia del aire
    float e; //Coeficiente de restitución
    float v;
    float dt; //Delta de tiempo
public:
    Bala_parabolica(float posx_, float posy_,float masa_, float radio_, float k_, float e_,float a_,float v_);
    ~Bala_parabolica();
    void ActualizarPosicion();
    void CalcularVelocidad();
    float getPx() const;
    float getPy() const;
    float getMasa() const;
    float getR() const;
    float getVx() const;
    float getVy() const;
    void set_vel(float vx_,float vy_, float px_,float py_);
    float getE() const;
    void setPx(float value);
    void setPy(float value);

};

#endif // BALA_PARABOLICA_H
