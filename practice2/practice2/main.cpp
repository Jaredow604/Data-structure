/*
 * UNIVERSIDAD DE GUADALAJARA
 * Centro Universitario de Ciencias Exactas e Ingenierías
 *
 * Estructuras de Datos IL3A54 Secc. D02
 * Práctica 2: ADT Colas
 *
 * Integrantes:
 * Duarte Garcia, Marcio Arie
 * Gradilla Vazquez, Brandon Moises
 * Ortega Garcia, Jared Misael
 */

#include <iostream>
#include "Alumno.h"
#include "Cola.h"
#define a_ACUTE '\xA0'
#define e_ACUTE '\x82'
#define i_ACUTE '\xA1'
#define o_ACUTE '\xA2'
#define u_ACUTE '\xA3'
#define n_TILDE '\xA4'
#define E_ACUTE '\x90'
#define O_ACUTE '\xE0'
#define INVERTED_EXCLAMATION '\xAD'
enum OpcionMenu {
    INSERTAR = 1,
    ELIMINAR = 2,
    SALIR = 3
};
void mostrarMenu() {
    std::cout << "\n===== SISTEMA ADMINISTRADOR DE CONSTANCIAS =====\n";
    std::cout << "1. Dar de alta la solicitud de un alumno (insertar)\n";
    std::cout << "2. Elaborar una constancia (eliminar)\n";
    std::cout << "3. Salir\n";
    std::cout << "==================================================\n";
    std::cout << "Elige tu opci" << o_ACUTE << "n: ";
}

int main() {
    Cola<Alumno> solicitudes;
    Alumno datosAlumnos[] = {
        Alumno("Arturo Huerta", "Electr\242nica", 12, 96.8),
        Alumno("Oscar Espinoza", "Mec\240nica El\x82ctrica", 15, 93.4),
        Alumno("Josu\x82 Ram\xA1rez", "Medicina", 18, 93.5),
        Alumno("Sergio Ram\xA1rez", "Psicolog\xA1a", 10, 86.8)
    };

    int contadorAlumnos = 0;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case INSERTAR: {
                if (contadorAlumnos < 4) {
                    Alumno nuevoAlumno = datosAlumnos[contadorAlumnos];
                    if (solicitudes + nuevoAlumno) {
                        std::cout << "\n>> Solicitud de '" << nuevoAlumno.getNombre() << "' ha sido dada de alta exitosamente.\n";
                        contadorAlumnos++;
                    } else {
                        std::cout << "\n>> ERROR: La cola de solicitudes est" << a_ACUTE << " llena. No se pueden agregar m" << a_ACUTE << "s.\n";
                    }
                } else {
                     std::cout << "\n>> No hay m" << a_ACUTE << "s datos de alumnos pre-cargados para agregar.\n";
                }
                break;
            }
            case ELIMINAR: {
                Alumno alumnoAtendido;
                if (solicitudes - &alumnoAtendido) {
                    std::cout << "\n>> Elaborando constancia para el primer alumno en la cola...";
                    std::cout << alumnoAtendido;
                } else {
                    std::cout << "\n>> AVISO: La cola se encuentra vac" << i_ACUTE << "a. No hay solicitudes pendientes.\n";
                }
                break;
            }
            case SALIR: {
                std::cout << "\n>> Saliendo del programa. " << INVERTED_EXCLAMATION << "Hasta luego!\n";
                break;
            }
            default: {
                std::cout << "\n>> Opci" << o_ACUTE << "n no v" << a_ACUTE << "lida. Por favor, intenta de nuevo.\n";
                break;
            }
        }
    } while (opcion != SALIR);

    return 0;
}

