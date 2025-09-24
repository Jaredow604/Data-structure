#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#include <string>

class Deportista
{
public:
    Deportista(int = 0, const std::string& = "", int = 0, const std::string& = "");
    void establecerNoSocio(int);
    int obtenerNoSocio() const;
    void establecerNombre(const std::string&);
    std::string obtenerNombre() const;
    void establecerEdad(int);
    int obtenerEdad() const;
    void establecerDisciplina(const std::string&);
    std::string obtenerDisciplina() const;

private:
    int noSocio;
    char nombre[30];
    int edad;
    char disciplina[20];
};

#endif
