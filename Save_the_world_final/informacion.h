#ifndef INFORMACION_H
#define INFORMACION_H

#include <string.h>
#include <string>

using namespace std;

/* Esta clase tiene como objetivo almacenar los datos
 * del jugador para poder pasarlos entre ventanas mas
 * facilmente.
 */

class Informacion
{
private:

    string Nombre_equipo;
    string clave;
    int modo; //Si es un jugador o multijugador
    int semilla; //Determina el nivel
    int puntaje;

public:
    Informacion();
    string getNombre_equipo() const;
    void setNombre_equipo(const string &value);
    string getClave() const;
    void setClave(string value);
    int getSemilla() const;
    void setSemilla(int value);
    int getModo() const;
    void setModo(int value);
    int getPuntaje() const;
    void setPuntaje(int value);
};

#endif // INFORMACION_H
