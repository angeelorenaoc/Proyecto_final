#ifndef CUERPO_H
#define CUERPO_H


class Cuerpo
{
private:
    float px;
    float py;
    float masa;
    float r;
    float vx;
    float vy;
    float angulo;
    float ax;
    float ay;
    float g;
    float K; //Resistencia del aire
    float e; //Coeficiente de restitución
    float v; //vector velocidad
    float dt;
    float rr;
public:
    Cuerpo(float posx_, float posy_, float velx_, float vely_,float masa_, float radio_, float k_, float e_, float rr_);
    ~Cuerpo();
    void Actualizar();
    float getPx() const;
    float getPy() const;
    float getMasa() const;
    float getR() const;
    float getVx() const;
    float getVy() const;
    void set_vel(float vx_,float vy_, float px_,float py_);
    float getE() const;
    void setAx(float value);
    void setAy(float value);
    void setPx(float value);
    void setPy(float value);
    float getRr() const;
};

#endif // CUERPO_H
