#include "Cola.h"

class Producto
{
private:
    int Clave;
    char NomProd[64];
    double Precio;
public:
    Producto();
    Producto(int, char[], double);
    double RegresaPrecio();
    friend istream &operator>>(istream &, Producto &);
    friend ostream &operator<<(ostream &, Producto &);
};

Producto::Producto()
{}

Producto::Producto(int Cla, char NomP[], double Pre)
{
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

double Producto::RegresaPrecio()
{
    return Precio;
}

istream &operator>>(istream &Lee, Producto &ObjProd)
{
    cout<<"\n\nIngrese clave del producto: ";
    Lee>>ObjProd.Clave;
    cout<<"\n\nIngrese nombre del producto: ";
    Lee>>ObjProd.NomProd;
    cout<<"\n\nIngrese precio: ";
    Lee>>ObjProd.Precio;
    return Lee;
}

ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{
    Escribe<<"\n\nDatos del producto\n";
    Escribe<<"\nClave: "<<ObjProd.Clave;
    Escribe<<"\nNombre: "<<ObjProd.NomProd;
    Escribe<<"\nPrecio: "<<ObjProd.Precio;
    return Escribe;
}

int Menu()
{
    int Resp;
    do {
        cout<<"\n\nIngrese operación a registrar: ";
        cout<<"\n1- Compra de un producto ";
        cout<<"\n2- Venta de un producto\n ";
        cout<<"\n3- Termina el registro\n ";
        cin>>Resp;
    } while (Resp != 1 && Resp != 2 && Resp != 3);
    return Resp;
}

void main()
{
    Cola<Producto> Deposito;
    Producto Prod;
    int Opc;
    double Total= 0;
    Opc= Menu();
    while (Opc == 1 || Opc== 2)
    {
        switch (Opc)
        {
            case 1: cin>>Prod;
                if (!(Deposito + Prod))
                    cout<<"\n\nNo hay lugar en el depósito para registrar el producto.\n";
                break;
            case 2: if (Deposito - &Prod)
                {
                    cout<<Prod;
                    Total= Total + Prod.RegresaPrecio();
                }
                else
                    cout<<"\n\n\nYa no hay productos en el depósito.\n\n";
                break;
        }
        Opc= Menu();
    }
    cout<<"\n\n\nTotal vendido: "<<Total<<endl;
}
