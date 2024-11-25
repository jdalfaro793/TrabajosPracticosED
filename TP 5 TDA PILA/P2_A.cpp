#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


const int MAX = 20;

typedef char tcontenedor[MAX];

typedef struct tpila
{
    tcontenedor datos;
    int cima;
};



void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, char valor);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);
void consultar_ultimo(tpila pila);
void extraer_valor(tpila &pila);

void menu(char &op);

int main(int argc, char *argv[])
{

    char op;
    tpila pila;

    char nuevo, extraido;


    iniciar_pila(pila);






    do
    {

        system("cls");
        menu(op);

        switch(op)
        {
        case 'a':
            cout << "ingrese valor: ";
            cin>>nuevo;

            agregar_valor(pila, nuevo);
            break;
        case 'b':

            extraer_valor(pila);


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
    pila.cima = -1;
}


void agregar_valor(tpila &pila, char valor)
{
	int i;
	
    if(pila_llena(pila))
    {
        cout << "pila llena" << endl;
    }
    else
    {
		
		if(pila.cima==-1){
			
			pila.cima++;
			pila.datos[pila.cima]=valor;
		
		}else{
			i=pila.cima;
			while(i>=0){
				pila.datos[i+1]=pila.datos[i];
				i--;
			}
			
			
			pila.datos[0]= valor;
			pila.cima++;
			
		}
        cout << "agregado" << endl;
    }

}

void extraer_valor(tpila &pila)
{
	int i;
    if(pila_vacia(pila))
    {
        cout << "pila vacia"<<endl;
    }
    else
    {
		
        cout << "extrayendo valor: " << pila.datos[0] << endl;
		i=-1;
		while(i<pila.cima){
			pila.datos[i]=pila.datos[i+1];
			i++;
		}
		
        pila.cima--;
    }



}

bool pila_vacia(tpila pila)
{
    bool res;

    res = pila.cima == -1;

    return res;
}


bool pila_llena(tpila pila)
{
    bool res;

    res = pila.cima == MAX - 1;

    return res;
}

void consultar_ultimo(tpila pila)
{
    if(pila_vacia(pila))
        cout << "pila vacia" << endl;
    else
        cout << "valor: " << pila.datos[0] << endl;
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

