#include <iostream>
using namespace std;
#define MAX 100

template <class T>
class Arreglo
{
private:
    T Datos[MAX];
    int Tam;
public:
    Arreglo();
    int RegresaTam();
    T RegresaValor(int);
    void AsignaValor(int, T);
    void Intercambia(int, int);
    void IntercDirectoIzq();
    void InsercionDirecta();
    void SeleccionDirecta();
    void QuickSort();
    void Reduce(int, int);
    void SeleccionDirectaDesc();
    void Lectura();
    void Escribe();
};
template <class T>
Arreglo<T>::Arreglo()
{
    Tam = 0;
}

template <class T>
int Arreglo<T>::RegresaTam()
{
    return Tam;
}

template <class T>
T Arreglo<T>::RegresaValor(int Indice)
{
    return Datos[Indice];
}

template <class T>
void Arreglo<T>::AsignaValor(int Indice, T Valor)
{
    Datos[Indice] = Valor;
}

template <class T>
void Arreglo<T>::Lectura()
{
    int Indice;
    do {
        cout << "\n\n Ingrese total de elementos: ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);

    for (Indice = 0; Indice < Tam; Indice++)
    {
        cout << "\nIngrese el " << Indice + 1 << " dato: ";
        cin >> Datos[Indice];
    }
}

template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0)
    {
        cout << "\n\n";
        for (Indice = 0; Indice < Tam; Indice++)
            cout << '\t' << Datos[Indice];
        cout << "\n\n";
    }
    else
        cout << "\n No hay elementos almacenados.";
}

template <class T>
void Arreglo<T>::Intercambia(int Ind1, int Ind2)
{
    T Auxiliar;
    Auxiliar = Datos[Ind1];
    Datos[Ind1] = Datos[Ind2];
    Datos[Ind2] = Auxiliar;
}

template <class T>
void Arreglo<T>::IntercDirectoIzq()
{
    int Ind1, Ind2;
    for (Ind1 = 1; Ind1 < Tam; Ind1++)
        for (Ind2 = Tam - 1; Ind2 >= Ind1; Ind2--)
            if (Datos[Ind2 - 1] > Datos[Ind2])
                Intercambia(Ind2 - 1, Ind2);
}

template <class T>
void Arreglo<T>::InsercionDirecta()
{
    T Auxiliar;
    int Indice, IndAux;
    for (Indice = 1; Indice < Tam; Indice++)
    {
        Auxiliar = Datos[Indice];
        IndAux = Indice - 1;
        while ((IndAux >= 0) && (Auxiliar < Datos[IndAux]))
        {
            Datos[IndAux + 1] = Datos[IndAux];
            IndAux--;
        }
        Datos[IndAux + 1] = Auxiliar;
    }
}

template <class T>
void Arreglo<T>::SeleccionDirecta()
{
    T Menor;
    int Ind1, Ind2, Ind3;
    for (Ind1 = 0; Ind1 < Tam - 1; Ind1++)
    {
        Menor = Datos[Ind1];
        Ind2 = Ind1;
        for (Ind3 = Ind1 + 1; Ind3 < Tam; Ind3++)
            if (Datos[Ind3] < Menor)
            {
                Menor = Datos[Ind3];
                Ind2 = Ind3;
            }
        Datos[Ind2] = Datos[Ind1];
        Datos[Ind1] = Menor;
    }
}

template <class T>
void Arreglo<T>::QuickSort()
{
    Reduce(0, Tam - 1);
}

template <class T>
void Arreglo<T>::Reduce(int Inicio, int Fin)
{
    if (Tam > 0)
    {
        int Izq, Der, Posic, Bandera;
        Izq = Inicio;
        Der = Fin;
        Posic = Inicio;
        Bandera = 1;
        while (Bandera)
        {
            Bandera = 0;
            while ((Datos[Posic] <= Datos[Der]) && (Posic != Der))
                Der--;
            if (Posic != Der)
            {
                Intercambia(Posic, Der);
                Posic = Der;
                while ((Datos[Posic] >= Datos[Izq]) && (Posic != Izq))
                    Izq++;
                if (Posic != Izq)
                {
                    Bandera = 1;
                    Intercambia(Posic, Izq);
                    Posic = Izq;
                }
            }
        }
        if ((Posic - 1) > Inicio)
            Reduce(Inicio, Posic - 1);
        if (Fin > (Posic + 1))
            Reduce(Posic + 1, Fin);
    }
}

template <class T>
void Arreglo<T>::SeleccionDirectaDesc()
{
    T Mayor;
    int Ind1, Ind2, Ind3;
    for (Ind1 = 0; Ind1 < Tam - 1; Ind1++)
    {
        Mayor = Datos[Ind1];
        Ind2 = Ind1;
        for (Ind3 = Ind1 + 1; Ind3 < Tam; Ind3++)
            if (Datos[Ind3] > Mayor)
            {
                Mayor = Datos[Ind3];
                Ind2 = Ind3;
            }
        Datos[Ind2] = Datos[Ind1];
        Datos[Ind1] = Mayor;
    }
}


int main()
{
    Arreglo<int> miArreglo;
    int opcion;

    do
    {
        cout << "\n- MENU - METODOS DE ORDENAMIENTO -\n";
        cout << "1. Llenar el arreglo\n";
        cout << "2. Mostrar el arreglo\n";
        cout << "3. Metodo Intercambio directo por la izquierda\n";
        cout << "4. Metodo Insercion directa\n";
        cout << "5. Metodo Seleccion directa\n";
        cout << "6. Metodo QuickSort\n";
        cout << "7. Metodo para ordenar de manera descendente\n";
        cout << "0. Salir\n";
        cout << "Elige tu opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            miArreglo.Lectura();
            break;
        case 2:
            miArreglo.Escribe();
            break;
        case 3:
            miArreglo.IntercDirectoIzq();
            cout << "\nArreglo ordenado por Intercambio Directo:\n";
            miArreglo.Escribe();
            break;
        case 4:
            miArreglo.InsercionDirecta();
            cout << "\nArreglo ordenado por Insercion Directa:\n";
            miArreglo.Escribe();
            break;
        case 5:
            miArreglo.SeleccionDirecta();
            cout << "\nArreglo ordenado por Seleccion Directa:\n";
            miArreglo.Escribe();
            break;
        case 6:
            miArreglo.QuickSort();
            cout << "\nArreglo ordenado por QuickSort:\n";
            miArreglo.Escribe();
            break;
        case 7:
            miArreglo.SeleccionDirectaDesc();
            cout << "\nArreglo ordenado de forma descendente:\n";
            miArreglo.Escribe();
            break;
        case 0:
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "\nOpcion no valida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
