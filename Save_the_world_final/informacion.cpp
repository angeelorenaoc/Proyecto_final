#include "informacion.h"

string Informacion::getNombre_equipo() const
{
    return Nombre_equipo;
}

void Informacion::setNombre_equipo(const string &value)
{
    Nombre_equipo = value;
}

int Informacion::getClave() const
{
    return clave;
}

void Informacion::setClave(int value)
{
    clave = value;
}

int Informacion::getSemilla() const
{
    return semilla;
}

void Informacion::setSemilla(int value)
{
    semilla = value;
}

int Informacion::getModo() const
{
    return modo;
}

void Informacion::setModo(int value)
{
    modo = value;
}

int Informacion::getPuntaje() const
{
    return puntaje;
}

void Informacion::setPuntaje(int value)
{
    puntaje = value;
}

Informacion::Informacion()
{

}
