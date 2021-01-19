#ifndef INFORMACION_H
#define INFORMACION_H

#include <string.h>
#include <string>

using namespace std;

class Informacion
{
private:
    string Nombre_equipo;
    int clave;
    int semilla;
    int modo;
    int puntaje;

public:
    Informacion();
    string getNombre_equipo() const;
    void setNombre_equipo(const string &value);
    int getClave() const;
    void setClave(int value);
    int getSemilla() const;
    void setSemilla(int value);
    int getModo() const;
    void setModo(int value);
    int getPuntaje() const;
    void setPuntaje(int value);
};

#endif // INFORMACION_H
