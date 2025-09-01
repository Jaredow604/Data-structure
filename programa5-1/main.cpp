#include <iostream>

using namespace std;
#define MAX 10

template <class T>
class Pila{
    private:
        T EspacioPila[MAX];
        int Tope;
    public:
        Pila();
        void Push(T Dato);
        void Pop(T *Dato);
        int PilaLLena();
        int PilaVacia();
};

template <class T>
Pila<T>::Pila(){
    Tope = -1;
}

template <class T>
void Pila<T>::Push(T Dato){
    EspacioPila[++Tope] = Dato;
}

template <class T>
void Pila<T>::Pop(T *Dato){
    *Dato = EspacioPila[Tope--];
}

template <class T>
int Pila<T>::PilaVacia()
{
    if (Tope == -1){
        return 1;
    } else {
        return 0;
    }
}

template <class T>
int Pila<T>::PilaLLena()
{
    if (Tope == MAX - 1){
        return 1;
    } else {
        return 0;
    }
}

void FuncionUsaPila()
{
    Pila<int> ObjPila;
    int valor = 0;

    cout << "Insertando elementos en la pila..." << endl;
    while(ObjPila.PilaLLena() != 1){
        ObjPila.Push(valor);
        cout << "Push: " << valor << endl;
        valor++;
    }

    cout << "\nExtrayendo elementos de la pila..." << endl;
    while(ObjPila.PilaVacia() != 1){
        ObjPila.Pop(&valor);
        cout << "Pop: " << valor << endl;
    }
}

int main()
{
    FuncionUsaPila();
    return 0;
}
