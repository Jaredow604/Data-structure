#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // para exit
#include "Deportista.h" // Definición de la clase Deportista

int main()
{
    // Abre el archivo para lectura y escritura en modo binario
    std::fstream archivoDeportistas("deportistas.dat", std::ios::in | std::ios::out | std::ios::binary);

    // Si el archivo no se puede abrir, termina el programa
    if (!archivoDeportistas)
    {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        exit(1);
    }

    int noSocio;
    char nombre[30];
    int edad;
    char disciplina[20];

    std::cout << "Escriba el numero de socio (de 1 a 100, 0 para terminar la entrada)\n? ";

    Deportista deportista; // Objeto para almacenar los datos
    std::cin >> noSocio;

    // Bucle para leer los datos del usuario y escribirlos en el archivo
    while (noSocio > 0 && noSocio <= 100)
    {
        // Solicita al usuario que introduzca nombre, edad y disciplina
        std::cout << "Escriba nombre, edad y disciplina\n? ";
        std::cin >> std::setw(30) >> nombre;
        std::cin >> edad;
        std::cin >> std::setw(20) >> disciplina;

        // Establece los datos en el objeto deportista
        deportista.establecerNoSocio(noSocio);
        deportista.establecerNombre(nombre);
        deportista.establecerEdad(edad);
        deportista.establecerDisciplina(disciplina);

        // Busca la posición correcta en el archivo
        archivoDeportistas.seekp((deportista.obtenerNoSocio() - 1) * sizeof(Deportista));

        // Escribe el objeto deportista en el archivo
        archivoDeportistas.write(reinterpret_cast<const char *>(&deportista), sizeof(Deportista));

        // Pide al usuario el siguiente número de socio
        std::cout << "Escriba el numero de socio (0 para terminar)\n? ";
        std::cin >> noSocio;
    }

    return 0;
}
