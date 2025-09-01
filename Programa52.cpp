#define MAX 10
template <class T>
class Pila
{
private:
    T EspacioPila[MAX];
    int Tope;
public:
    Pila();
    void operator + (T);
    void operator - (T *);
    int PilaLlena();
    int PilaVacia();
};

template <class T>
Pila<T>::Pila():Tope(-1)
{}

template <class T>
int Pila<T>::PilaLlena()
{
    if (Tope == MAX-1)
        return 1;
    else
        return 0;
}

template <class T>
int Pila<T>::PilaVacia()
{
    if (Tope == -1)
        return 1;
    else
        return 0;
}

template <class T>
void Pila<T>::operator + (T Valor)
{
    Tope++;
    EspacioPila[Tope]= Valor;
}

template <class T>
void Pila<T>::operator - (T *Valor)
{
    *Valor= EspacioPila[Tope];
    Tope--;
}

void UsaSobrecargaOperadores()
{
    Pila <int> ObjPila;
    int Indice;

    if (ObjPila.PilaVacia())
        for (Indice= 0; Indice < MAX; Indice++)
            ObjPila + Indice*2;

    while ( !ObjPila.PilaVacia() )
    {
        ObjPila - &Indice;
        cout << '\n' << Indice;
    }
}
