#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX = 15;

typedef int tpila[MAX];


void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, int valor);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);
void consultar_ultimo(tpila pila);
int extraer_valor(tpila &pila);

void menu(char &op);

int main(int argc, char *argv[])
{

    char op;
    tpila pila;

    int nuevo, extraido;
	
    iniciar_pila(pila);

    do
    {
        system("cls");
        menu(op);
        switch(op)
        {
        case 'a':
            cout << "ingrese valor: ";
            cin >> nuevo;
            agregar_valor(pila, nuevo);
            break;
        case 'b':
            extraido=extraer_valor(pila);
			
			if(extraido!=-99999)
				cout<<"extraido: "<<extraido<<endl;
			else 
				cout<<"pila vacia"<<endl;
            break;
        case 'c':
            consultar_ultimo(pila);
            break;
        case 'd':
            cout << "fin" << endl;
            break;
        }
        system("pause");
    }
    while(op != 'd');

    return 0;
}




void iniciar_pila(tpila &pila)
{
    pila[0] = 0;
}


void agregar_valor(tpila &pila, int valor)
{
    int i;

    if(pila_llena(pila))
    {
        cout << "pila llena" << endl;
    }
    else
    {

            pila[0] ++;
			
            pila[pila[0]]=valor;

    }

}

int extraer_valor(tpila &pila)
{
    int res,i;
    if(pila_vacia(pila))
    {
        res=-99999;
    }
    else
    {
		res=pila[pila[0]];
        pila[0]--;
    }

	return res;
}

bool pila_vacia(tpila pila)
{
    bool res;

    res = pila[0] == 0;

    return res;
}


bool pila_llena(tpila pila)
{
    bool res;

    res = pila[0] == MAX -1;

    return res;
}

void consultar_ultimo(tpila pila)
{
    if(pila_vacia(pila))
        cout << "pila vacia" << endl;
    else
        cout << "valor: " << pila[pila[0]] << endl;
}


void menu(char &op)
{

    cout << "a-Agregar valor" << endl;
    cout << "b-Quitar valor" << endl;
    cout << "c-Consultar valor" << endl;
    cout << "d-Salir" << endl;
    cout << "ingrese opcion: ";
    cin >> op;
}

