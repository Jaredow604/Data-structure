#include "Alumno.h"
#include <cstring>
#include <iomanip>
Alumno::Alumno() {
    strcpy(nombreAlumno, "N/A");
    strcpy(nombreCarrera, "N/A");
    totalMateriasAprobadas = 0;
    promedioGeneral = 0.0;
}
Alumno::Alumno(const char* nom, const char* carr, int mat, double prom) {
    strcpy(nombreAlumno, nom);
    strcpy(nombreCarrera, carr);
    totalMateriasAprobadas = mat;
    promedioGeneral = prom;
}
const char* Alumno::getNombre() const {
    return nombreAlumno;
}
std::ostream& operator<<(std::ostream& os, const Alumno& al) {
    os << "\n----------------------------------------\n";
    os << "       CONSTANCIA DE ESTUDIOS\n";
    os << "----------------------------------------\n";
    os << "Nombre del Alumno: " << al.nombreAlumno << "\n";
    os << "Carrera:             " << al.nombreCarrera << "\n";
    os << "Materias Aprobadas:  " << al.totalMateriasAprobadas << "\n";
    os << "Promedio General:    " << std::fixed << std::setprecision(1) << al.promedioGeneral << "\n";
    os << "----------------------------------------\n";
    return os;
}
