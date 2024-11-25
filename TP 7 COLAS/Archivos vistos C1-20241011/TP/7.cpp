/*
Aplicando el TDA cola implementado en el ejercicio 6.a, diseñe un algoritmo que permita convertir una cadena ingresada
por el usuario a mayúsculas/minúsculas según elección de éste. Por ejemplo:
Cadena ingresada: Soy un programador del 2024
Selección de conversión M (mayúsculas) o m (minúsculas): M
Cadena en mayúsculas: SOY UN PROGRAMADOR DEL 2024
*/

#include <iostream>

using namespace std;

const int MAX = 50;

typedef struct tnodo *pnodo;

typedef struct tnodo
{
    char dato;
    pnodo sig;
};

typedef struct tcola
{
    pnodo inicio;
    pnodo final;
    int cant;
};

void iniciar_cola(tcola &q);
void crear_nodo(pnodo &nodo, char valor);
void agregar_cola(tcola &q, pnodo nuevo);
char quitar_cola(tcola &q);
bool cola_llena(tcola q);
bool cola_vacia(tcola q);
char  primero_cola(tcola q);
char ultimo_cola(tcola q);

main()
{

    int op;
    char valor, sel;
    tcola cola,salida;
    pnodo nuevo;


    iniciar_cola(cola);
	iniciar_cola(salida);

	cout << "Ingrese cadena: ";
	do{
		valor=getchar();
		if(valor!='\n'){
			crear_nodo(nuevo, valor);
			agregar_cola(cola, nuevo);				
		}
	} while(valor!='\n');
	
	
	do{
		cout<<"Selección de conversión M (mayúsculas) o m (minúsculas): ";
		cin>>sel;
	}while(sel!='M'&& sel!='m');
	
	
	if(sel=='M'){
		while(!cola_vacia(cola)){
			crear_nodo(nuevo, toupper( quitar_cola(cola)) );
			
			agregar_cola(salida,nuevo);		
		}

	}
	else{
		while(!cola_vacia(cola)){
			crear_nodo(nuevo, tolower( quitar_cola(cola)) );
			
			agregar_cola(salida,nuevo);
		}
	}
	
	while(!cola_vacia(salida)){
		cout<<quitar_cola(salida);
	}
}

void iniciar_cola(tcola &q)
{
    q.inicio = NULL;
    q.final = NULL;
    q.cant = 0;
}


void crear_nodo(pnodo &nodo, char valor)
{
    nodo = new tnodo;
    if(nodo != NULL)
    {
        nodo->dato = valor;
        nodo->sig = NULL;
    }
}

void agregar_cola(tcola &q, pnodo nuevo)
{
    if(cola_llena(q))
        cout << "cola llena" << endl;
    else
    {
        if(q.inicio == NULL)
        {
            q.inicio = nuevo;
            q.final = nuevo;
        }
        else
        {
            q.final->sig = nuevo;
            q.final = nuevo;
        }
        q.cant++;
    }

}



char quitar_cola(tcola &q)
{
	char extraido;
    pnodo sefue;
    if(cola_vacia(q))
        extraido = '@';
    else
    {
        sefue = q.inicio;

        q.inicio = sefue->sig;

        extraido = sefue->dato;

        delete(sefue);

        q.cant--;
    }

    return extraido;
}


bool cola_llena(tcola q)
{

    return q.cant == MAX;

}

bool cola_vacia(tcola q)
{

    return q.cant == 0;

}


char primero_cola(tcola q)
{

	char ext;
    if(cola_vacia(q))
        ext = '@';
    else
    {
        ext = q.inicio->dato;
    }

    return ext;
}


char ultimo_cola(tcola q)
{
	char ext;
    if(cola_vacia(q))
        ext = '@';
    else
    {
        ext = q.final->dato;
    }
    return ext;
}


