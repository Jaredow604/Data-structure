#include "PlanPila.h"

class Cheque
{
private:
    int Numero, CuentaADepositar;
    char Banco[10];
    double Monto;
public:
    Cheque();
    Cheque(int, char[], int, double);
    ~Cheque();
    void ImprimeDatos();
};

Cheque::Cheque()
{}

Cheque::Cheque(int NumCta, char *NomBco, int Cta, double Mon)
{
    Numero= NumCta;
    CuentaADepositar= Cta;
    Monto= Mon;
    strcpy(Banco, NomBco);
}

Cheque::~Cheque()
{}

void Cheque::ImprimeDatos()
{
    cout<< "\nNúmero de cheque: " << Numero;
    cout<< "\nDel banco: " << Banco;
    cout<< "\nDepositado en la cuenta: " << CuentaADepositar;
    cout<< "\nMonto: " << Monto<<endl;
}

class ChequeRechazado: public Cheque
{
private:
    double Cargo;
public:
    ChequeRechazado();
    ChequeRechazado(int, char[], int, double);
    ~ChequeRechazado();
    void ImprimeDatos();
};

ChequeRechazado::ChequeRechazado()
{}

ChequeRechazado::ChequeRechazado (int NumCta, char *NomBco, int Cta,
double Mon): Cheque(NumCta, NomBco, Cta, Mon)
{
    Cargo= Mon*0.10;
}

ChequeRechazado::~ChequeRechazado()
{}

void ChequeRechazado::ImprimeDatos()
{
    Cheque::ImprimeDatos();
    cout<<"\nCargo por rechazo: " << Cargo<<endl;
}

class Banco
{
private:
    Pila<Cheque> Cheques;
    Pila<ChequeRechazado> ChequesRe;
public:
    Banco();
    ~Banco();
    void ProcesarCheque();
    void ProcesarChequeR();
    void RegistroCheque(Cheque);
    void RegistroChequeR(ChequeRechazado);
};

Banco::Banco()
{}

Banco::~Banco()
{}

void Banco::ProcesarCheque()
{
    Cheque ChequeCli;
    if (!Cheques.PilaVacia())
    {
        Cheques - &ChequeCli;
        cout<< "\n\n\nCheque procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else
        cout<<"\n\nNo hay cheques por procesar.\n\n ";
}

void Banco::ProcesarChequeR()
{
    ChequeRechazado ChequeCli;
    if (!ChequesRe.PilaVacia())
    {
        ChequesRe - &ChequeCli;
        cout<< "\n\n\nCheque rechazado procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else
        cout<<"\n\nNo hay cheques rechazados por procesar.\n\n ";
}

void Banco::RegistroCheque(Cheque ChequeCli)
{
    if (!Cheques.PilaLlena())
    {
        cout<< "\n\n\nRegistrando el cheque: ";
        ChequeCli.ImprimeDatos();
        Cheques + ChequeCli;
    }
    else
        cout<<"\n\nNo se pudo registrar el cheque por falta de espacio. \n\n ";
}

void Banco::RegistroChequeR(ChequeRechazado ChequeCli)
{
    if (!ChequesRe.PilaLlena())
    {
        cout<< "\n\n\nRegistrando el cheque rechazado: ";
        ChequeCli.ImprimeDatos();
        ChequesRe + ChequeCli;
    }
    else
        cout<<"\n\nNo se pudo registrar el cheque rechazado por falta de espacio. \n\n ";
}

void main ()
{
    Cheque Uno (1718, "Banamex", 14418, 18000.00);
    Cheque Dos (1105, "Bancomer", 13200, 12319.62);
    ChequeRechazado Tres (1816, "Banorte", 12850, 14000.00);
    ChequeRechazado Cuatro (1905, "Bancomer", 13468, 50000.00);

    Banco MiBanco;

    MiBanco.RegistroCheque(Uno);
    MiBanco.RegistroCheque(Dos);
    MiBanco.RegistroChequeR(Tres);
    MiBanco.RegistroChequeR(Cuatro);

    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();
    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();

    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();
}
