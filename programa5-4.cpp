#define MAX 10

template <class T>
class Cola
{
private:
    T EspacioCola[MAX];
    int Frente, Final;
public:
    Cola();
    void InsertaCola(T);
    void EliminaCola(T*);
    int ColaLlena();
    int ColaVacia();
};

template <class T>
Cola<T>::Cola()
{
    Frente= -1;
    Final= -1;
}

template <class T>
void Cola<T>::InsertaCola(T Dato)
{
    EspacioCola[++Final]= Dato;
    if (Final == 0)
        Frente= 0;
}

template <class T>
void Cola<T>::EliminaCola(T *Dato)
{
    *Dato= EspacioCola[Frente];
    if (Frente == Final)
    {
        Frente= -1;
        Final= -1;
    }
    else
        Frente++;
}

template <class T>
int Cola<T>::ColaLlena()
{
    if (Final == MAX-1)
        return 1;
    else
        return 0;
}

template <class T>
int Cola<T>::ColaVacia()
{
    if (Frente == -1)
        return 1;
    else
        return 0;
}

void UsaClaseCola ()
{
    Cola<int> ObjCola;
    int Valor;
    if (ObjCola.ColaLlena() != 1)
        ObjCola.InsertaCola(5);
    else
        cout<<"\nError de desbordamiento. Cola llena. \n";
    if (ObjCola.ColaVacia() != 1)
    {
        ObjCola.EliminaCola(&Valor);
        cout<<Valor<<"\n";
    }
    else
        cout<<"\nSubdesbordamiento. Cola vacía.\n";
}
