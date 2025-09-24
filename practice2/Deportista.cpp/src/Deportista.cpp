#include "Deportista.h"
#include <string>
#include <cstring> // Para strncpy

// Constructor de la clase Deportista
Deportista::Deportista(int numeroSocio, const std::string& nombreDeportista, int edadDeportista, const std::string& disciplinaDeportista)
{
    establecerNoSocio(numeroSocio);
    establecerNombre(nombreDeportista);
    establecerEdad(edadDeportista);
    establecerDisciplina(disciplinaDeportista);
}

// Obtiene el número de socio
int Deportista::obtenerNoSocio() const
{
    return noSocio;
}

// Establece el número de socio
void Deportista::establecerNoSocio(int numeroSocio)
{
    noSocio = numeroSocio;
}

// Obtiene el nombre del deportista
std::string Deportista::obtenerNombre() const
{
    return nombre;
}

// Establece el nombre del deportista
void Deportista::establecerNombre(const std::string& cadenaNombre)
{
    const char *valorNombre = cadenaNombre.data();
    int longitud = cadenaNombre.size();
    longitud = (longitud < 30 ? longitud : 29);
    strncpy(nombre, valorNombre, longitud);
    nombre[longitud] = '\0'; // Agrega el carácter nulo de terminación
}

// Obtiene la edad del deportista
int Deportista::obtenerEdad() const
{
    return edad;
}

// Establece la edad del deportista
void Deportista::establecerEdad(int edadDeportista)
{
    edad = edadDeportista;
}

// Obtiene la disciplina del deportista
std::string Deportista::obtenerDisciplina() const
{
    return disciplina;
}

// Establece la disciplina del deportista
void Deportista::establecerDisciplina(const std::string& cadenaDisciplina)
{
    const char *valorDisciplina = cadenaDisciplina.data();
    int longitud = cadenaDisciplina.size();
    longitud = (longitud < 20 ? longitud : 19);
    strncpy(disciplina, valorDisciplina, longitud);
    disciplina[longitud] = '\0'; // Agrega el carácter nulo de terminación
}
