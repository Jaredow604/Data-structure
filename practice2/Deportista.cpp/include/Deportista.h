#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#include <string>

class Deportista
{
public:
    // Constructor predeterminado
    Deportista(int = 0, const std::string& = "", int = 0, const std::string& = "");

    // Funciones de acceso para el número de socio
    void establecerNoSocio(int);
    int obtenerNoSocio() const;

    // Funciones de acceso para el nombre
    void establecerNombre(const std::string&);
    std::string obtenerNombre() const;

    // Funciones de acceso para la edad
    void establecerEdad(int);
    int obtenerEdad() const;

    // Funciones de acceso para la disciplina
    void establecerDisciplina(const std::string&);
    std::string obtenerDisciplina() const;

private:
    int noSocio;
    char nombre[30];
    int edad;
    char disciplina[20];
};

#endif
