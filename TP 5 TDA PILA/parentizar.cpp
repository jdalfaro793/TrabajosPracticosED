#include <iostream>
#include <stdio.h>
#include <string.h>



//correcto: [][][<><><>]{{}}
//incorrecto: [<>><<>]{}}}

using namespace std;


const int MAX = 15;

typedef char tcad[MAX];


typedef struct tpila
{
    tcad elementos;
    int cima;
};



void iniciar_pila(tpila &pila);
void agregar_pila(tpila &pila, char dato);
void quitar_pila(tpila &pila);
bool pila_vacia(tpila pila);
bool pila_llena(tpila pila);


bool esContrario(tpila pila, char dato);
void parentizacion(tcad cadena);

int main(int argc, char *argv[])
{

    tcad cadena;


    cout << "ingrese cadena" << endl;
    fflush(stdin);

    gets(cadena);


    parentizacion(cadena);



    return 0;
}



void parentizacion(tcad cadena)
{

    int i;
    tpila pila;

    iniciar_pila(pila);
	
    for(i = 0; i < strlen(cadena); i++)
    {
            if(esContrario(pila, cadena[i]))
            {
                quitar_pila(pila);
            }
            else
            {
                agregar_pila(pila, cadena[i]);
            }
    }
    if(pila_vacia(pila))
    {
        cout << "Correctamente parentizado" << endl;

    }
    else
    {
        cout << "Parentizacion incorrecta" << endl;
    }
}


void iniciar_pila(tpila &pila)
{
    pila.cima = -1;
}




void agregar_pila(tpila &pila, char dato)
{
    if(pila_llena(pila))
        cout << "pila llena" << endl;
    else
    {
        pila.cima++;
        pila.elementos[pila.cima] = dato;
    }
}





void quitar_pila(tpila &pila)
{
    if(pila_vacia(pila))
    {
        cout << "pila vacia" << endl;
    }
    else
    {
        pila.cima--;
    }
}



bool pila_vacia(tpila pila)
{
    bool r;

    r = pila.cima == -1;

    return r;
}


bool pila_llena(tpila pila)
{
    bool r;

    r = pila.cima == MAX - 1;

    return r;
}



bool esContrario(tpila pila, char dato)
{
    bool res = false;
    
	if(pila.elementos[pila.cima] == '[' && dato == ']')
        res = true;
    else if(pila.elementos[pila.cima] == '<' && dato == '>')
        res = true;
	else if(pila.elementos[pila.cima] == '{' && dato == '}')
		res = true;
	

    return res;
}
