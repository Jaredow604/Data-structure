#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include "Deportista.h"

int main()
{
    std::fstream archivoDeportistas("deportistas.dat", std::ios::in | std::ios::out | std::ios::binary);
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

    Deportista deportista;
    std::cin >> noSocio;

    while (noSocio > 0 && noSocio <= 100)
    {
        std::cout << "Escriba nombre, edad y disciplina\n? ";
        std::cin >> std::setw(30) >> nombre;
        std::cin >> edad;
        std::cin >> std::setw(20) >> disciplina;
        deportista.establecerNoSocio(noSocio);
        deportista.establecerNombre(nombre);
        deportista.establecerEdad(edad);
        deportista.establecerDisciplina(disciplina);
        archivoDeportistas.seekp((deportista.obtenerNoSocio() - 1) * sizeof(Deportista));
        archivoDeportistas.write(reinterpret_cast<const char *>(&deportista), sizeof(Deportista));
        std::cout << "Escriba el numero de socio (0 para terminar)\n? ";
        std::cin >> noSocio;
    }
    return 0;
}
