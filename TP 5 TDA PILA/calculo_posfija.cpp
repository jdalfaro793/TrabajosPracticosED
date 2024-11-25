
/*
8)
b) desarrolle un programa que, utilizando el TDA pila y sus operaciones básicas, calcule el valor de una
expresión posfija. Verifique el funcionamiento del programa utilizando una librería estática de pila y otra dinámica.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

const int MAX = 20;
typedef char tcad[MAX];

typedef struct tpila
{
    tcad datos;
    int cima;
};



void iniciar_pila(tpila &pila);
void agregar_pila(tpila &pila, char valor);
int quitar_pila(tpila &pila);
char tope_pila(tpila pila);
bool pila_vacia(tpila pila);
bool pila_llena(tpila pila);
int resultadoPosfija(tcad posfija);

int main()
{
    int resultado;
    tcad posfija;

    cout << "Ingrese Posfija: ";
    gets(posfija);
    resultado = resultadoPosfija(posfija);
    cout << "Resultado: " << resultado;
}

int resultadoPosfija(tcad posfija)
{
    tpila p;
    int i, num, extraido, resultado;

    iniciar_pila(p);

    for(i = 0; i < strlen(posfija); i++)
    {
        if(posfija[i] >= '0' && posfija[i] <= '9')
        {
            num = posfija[i] - '0';
            agregar_pila(p, num);
        }
        else
        {
            if(posfija[i] == '^')
            {
                extraido = quitar_pila(p);
                p.datos[p.cima] = pow(p.datos[p.cima], extraido);
            }
            if(posfija[i] == '*')
            {
                extraido = quitar_pila(p);
                p.datos[p.cima] = p.datos[p.cima] * extraido;
            }
            if(posfija[i] == '/')
            {
                extraido = quitar_pila(p);
                p.datos[p.cima] = p.datos[p.cima] / extraido;
            }
            if(posfija[i] == '+')
            {
                extraido = quitar_pila(p);
                p.datos[p.cima] = p.datos[p.cima] + extraido;
            }
            if(posfija[i] == '-')
            {
                extraido = quitar_pila(p);
                p.datos[p.cima] = p.datos[p.cima] - extraido;
            }
        }
    }
    resultado = quitar_pila(p);
    return resultado;
}



void iniciar_pila(tpila &pila)
{
    pila.cima = -1;
}


void agregar_pila(tpila &pila, char valor)
{
    if(pila_llena(pila))
    {
        cout << "pila llena" << endl;
    }
    else
    {
        pila.cima++;
        pila.datos[pila.cima] = valor;
    }
}


int quitar_pila(tpila &pila)
{
    int res;
    if(pila_vacia(pila))
    {
        res = -999999;
    }
    else
    {

        res = pila.datos[pila.cima];
        pila.cima--;



    }

    return res;
}
char tope_pila(tpila pila)
{
    char va;
    if(pila_vacia(pila))
    {
        va = '@';
    }
    else
    {
        va = pila.datos[pila.cima];
    }
    return va;
}

bool pila_vacia(tpila pila)
{
    bool resp;

    resp = pila.cima == -1;

    return resp;
}


bool pila_llena(tpila pila)
{
    bool resp;

    resp = pila.cima == MAX - 1;

    return resp;
}

