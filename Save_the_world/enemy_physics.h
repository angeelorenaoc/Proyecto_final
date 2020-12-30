#ifndef ENEMY_PHYSICS_H
#define ENEMY_PHYSICS_H

#include <QObject>
#include <math.h>
#include <cmath>

class enemy_physics: public QObject
{
private:
    float PX; //pos en x
    float PY; //pos en y
    float mass; // masa del enemy_physics
    float R; //radio del enemy_physics
    float VX; //vel en x
    float VY; //vel en y
    float angulo; //angulo en el que va el enemy_physics
    float AX; //acel en x
    float AY; //acel en y
    float G; //gravedad
    float K; //Resistencia del aire
    float e; //Coeficiente de restitucion
    float V; //vector de velocidad
    float dt; //delta tiempo
public:
    enemy_physics(float posX_,float posY_,float velX_,float velY_,float masa_,float radio_,float K_,float e_);
    ~enemy_physics();
    void Actualizar();

    float getPX() const;
    float getPY() const;
    float getMasa() const;
    float getR() const;
    float getVX() const;
    float getVY() const;
    void set_vel(float vx_,float vy_, float px_,float py_);
    float getE() const;
    void setPX(float value);
    void setPY(float value);
};

#endif // ENEMY_PHYSICS_H
