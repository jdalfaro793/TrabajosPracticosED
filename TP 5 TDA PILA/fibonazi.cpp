#include <iostream>
using namespace std;


const int MAX = 5;
typedef int tcontenedor[MAX];

typedef struct tpila
{
    tcontenedor datos;
    int cima;
};


void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, int valor);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);
void consultar_ultimo(tpila pila);
int extraer_valor(tpila &pila);
int tope_pila(tpila pila);

void fibonaxi(int valor);

void menu(char &op);

int main(int argc, char *argv[])
{

	int nuevo;
	
	cout << "ingrese termino: " ;
	cin >> nuevo;
	fibonaxi(nuevo);


    return 0;
}




void iniciar_pila(tpila &pila)
{
    pila.cima = -1;
}


void agregar_valor(tpila &pila, int valor)
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

int extraer_valor(tpila &pila)
{
    int extraido;
    if(pila_vacia(pila))
    {
        extraido = 9999999;
    }
    else
    {
        extraido = pila.datos[pila.cima];
        pila.cima--;
    }

    return extraido;

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



int tope_pila(tpila pila)
{
    int res;

    if(pila_vacia(pila))
        res = -9999;
    else
        res = pila.datos[pila.cima];

    return res;
}


void fibonaxi(int valor)
{
    tpila pila;
    int t1 = 1, t2 = 1, i = 2;

    iniciar_pila(pila);


    agregar_valor(pila, t1);
    agregar_valor(pila, t2); 

    if(valor == 1 || valor == 2)
    {
        cout << "termino vale: " << extraer_valor(pila);
    }
    else
    {
        while(i < valor)
        {
            t1 = tope_pila(pila);
            t2 = extraer_valor(pila) + extraer_valor(pila);
			
            agregar_valor(pila, t1);
            agregar_valor(pila, t2);
            i++;
        }
        cout << "termino vale: " << tope_pila(pila) << endl;
    }
}

