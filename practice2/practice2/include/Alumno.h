#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
class Alumno {
private:
    char nombreAlumno[50];
    char nombreCarrera[50];
    int totalMateriasAprobadas;
    double promedioGeneral;

public:
    Alumno();
    Alumno(const char* nom, const char* carr, int mat, double prom);
    const char* getNombre() const;
    friend std::ostream& operator<<(std::ostream& os, const Alumno& al);
};

#endif
