#include "Deportista.h"
#include <string>
#include <cstring> 

Deportista::Deportista(int numeroSocio, const std::string& nombreDeportista, int edadDeportista, const std::string& disciplinaDeportista)
{
    establecerNoSocio(numeroSocio);
    establecerNombre(nombreDeportista);
    establecerEdad(edadDeportista);
    establecerDisciplina(disciplinaDeportista);
}
int Deportista::obtenerNoSocio() const
{
    return noSocio;
}
void Deportista::establecerNoSocio(int numeroSocio)
{
    noSocio = numeroSocio;
}

std::string Deportista::obtenerNombre() const
{
    return nombre;
}

void Deportista::establecerNombre(const std::string& cadenaNombre)
{
    const char *valorNombre = cadenaNombre.data();
    int longitud = cadenaNombre.size();
    longitud = (longitud < 30 ? longitud : 29);
    strncpy(nombre, valorNombre, longitud);
    nombre[longitud] = '\0'; 
}

int Deportista::obtenerEdad() const
{
    return edad;
}

void Deportista::establecerEdad(int edadDeportista)
{
    edad = edadDeportista;
}

std::string Deportista::obtenerDisciplina() const
{
    return disciplina;
}

void Deportista::establecerDisciplina(const std::string& cadenaDisciplina)
{
    const char *valorDisciplina = cadenaDisciplina.data();
    int longitud = cadenaDisciplina.size();
    longitud = (longitud < 20 ? longitud : 19);
    strncpy(disciplina, valorDisciplina, longitud);
    disciplina[longitud] = '\0'; 
}
