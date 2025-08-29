#include <iostream>
#include <limits>

using namespace std;

#define MAX 80

template <class T>
class Arreglo 
{
private:
    T Datos[MAX];
    int Tam; 
public:
    Arreglo(); 
    void Escribe();
    int getTam();
    void setTam(int nuevoTam);
    T getDato(int indice);
    void setDato(int indice, T valor);
    T obtenerCalificacionMasAlta();
    T obtenerCalificacionMasBaja();
    int contarMenoresA(T valor);
    int contarMayoresA(T valor);
    T sumarCalificaciones();
};

template <class T>
Arreglo<T>::Arreglo()
{
    Tam = 0;
}

template <class T>
void Arreglo<T>::Escribe()
{
    if (Tam > 0)
    {
        cout << "\nCalificaciones almacenadas: " << endl;
        for (int i = 0; i < Tam; i++)
        {
            cout << Datos[i] << "\t";
        }
        cout << "\n";
    }
    else
    {
        cout << "\nNo hay calificaciones ingresadas." << endl;
    }
}

template <class T>
int Arreglo<T>::getTam() {
    return Tam;
}

template <class T>
void Arreglo<T>::setTam(int nuevoTam) {
    if (nuevoTam >= 0 && nuevoTam <= MAX) {
        Tam = nuevoTam;
    }
}

template <class T>
T Arreglo<T>::getDato(int indice) {
    if (indice >= 0 && indice < Tam) {
        return Datos[indice];
    }
    return T();
}

template <class T>
void Arreglo<T>::setDato(int indice, T valor) {
    if (indice >= 0 && indice < MAX) {
        Datos[indice] = valor;
    }
}

template <class T>
T Arreglo<T>::obtenerCalificacionMasAlta() {
    if (Tam == 0) return 0;
    T maxCal = Datos[0];
    for (int i = 1; i < Tam; i++) {
        if (Datos[i] > maxCal) {
            maxCal = Datos[i];
        }
    }
    return maxCal;
}

template <class T>
T Arreglo<T>::obtenerCalificacionMasBaja() {
    if (Tam == 0) return 0;
    T minCal = Datos[0];
    for (int i = 1; i < Tam; i++) {
        if (Datos[i] < minCal) {
            minCal = Datos[i];
        }
    }
    return minCal;
}

template <class T>
int Arreglo<T>::contarMenoresA(T valor) {
    int contador = 0;
    for (int i = 0; i < Tam; i++) {
        if (Datos[i] < valor) {
            contador++;
        }
    }
    return contador;
}

template <class T>
int Arreglo<T>::contarMayoresA(T valor) {
    int contador = 0;
    for (int i = 0; i < Tam; i++) {
        if (Datos[i] > valor) {
            contador++;
        }
    }
    return contador;
}

template <class T>
T Arreglo<T>::sumarCalificaciones() {
    T suma = 0;
    for (int i = 0; i < Tam; i++) {
        suma += Datos[i];
    }
    return suma;
}

void mostrarMenu() {
    cout << "\n--- MENÚ - SISTEMA DE CALIFICACIONES ---" << endl;
    cout << "1. Ingresar las calificaciones (Datos de prueba)" << endl;
    cout << "2. Imprimir las calificaciones" << endl;
    cout << "3. Mostrar calificación más alta" << endl;
    cout << "4. Mostrar calificación más baja" << endl;
    cout << "5. Imprimir total de calificaciones menores a 6" << endl;
    cout << "6. Imprimir total de calificaciones mayores a 8.5" << endl;
    cout << "7. Salir" << endl;
    cout << "ELIGE TU OPCIÓN: ";
}

int main() {
    Arreglo<float> calificaciones;
    bool datosIngresados = false;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0;
        }

        if (!datosIngresados && opcion > 1 && opcion < 7) {
            cout << "\n*** Error: Primero debe ingresar las calificaciones (opción 1). ***" << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\nIngresando datos de prueba..." << endl;
                float datosPrueba[] = {1.5, 7.6, 8.9, 3.4, 6.3, 8.7, 6.4, 4.3, 2.5, 7.2, 
                                       9.1, 5.7, 9.9, 6.2, 8.6, 7.7, 1.8, 2.9, 1.9, 2.0};
                int N = 20;
                calificaciones.setTam(N);
                for (int i = 0; i < N; i++) {
                    calificaciones.setDato(i, datosPrueba[i]);
                }
                datosIngresados = true;
                cout << "Se han ingresado 20 calificaciones." << endl;
                break;
            }
            case 2:
                calificaciones.Escribe();
                break;
            case 3:
                cout << "\nLa calificación más alta es: " << calificaciones.obtenerCalificacionMasAlta() << endl;
                break;
            case 4:
                cout << "\nLa calificación más baja es: " << calificaciones.obtenerCalificacionMasBaja() << endl;
                break;
            case 5:
                cout << "\nTotal de calificaciones menores a 6: " << calificaciones.contarMenoresA(6.0f) << endl;
                break;
            case 6:
                cout << "\nTotal de calificaciones mayores a 8.5: " << calificaciones.contarMayoresA(8.5f) << endl;
                break;
            case 7:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpción no válida. Por favor, intente de nuevo." << endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}
