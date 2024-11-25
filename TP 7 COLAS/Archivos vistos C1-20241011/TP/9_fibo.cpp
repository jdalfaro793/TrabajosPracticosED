/*

Aplicando el TDA cola y sus operaciones básicas desarrolle algoritmos que permitan
a) calcular un término cualquiera de la serie de Fibonacci


*/



#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAX = 10;

typedef struct tnodo *pnodo;

typedef struct tnodo
{
	int dato;
	pnodo sig;
};

typedef struct tcola
{
	pnodo inicio;
	pnodo final;
	int cant;
};

void iniciar_cola(tcola &q);
void crear_nodo(pnodo &nodo, int valor);
void agregar_cola(tcola &q, pnodo nuevo);
int quitar_cola(tcola &q);
bool cola_llena(tcola q);
bool cola_vacia(tcola q);
int  primero_cola(tcola q);
int ultimo_cola(tcola q);

int termino_fibo(int t);

main()
{	
	int t;
	
	do{
		cout << "Ingrese termino serie fibonacci: ";
		cin>>t;
	}while(t<1);
	
	cout<<"termino es: "<<termino_fibo(t)<<endl;
	
}

void iniciar_cola(tcola &q)
{
	q.inicio = NULL;
	q.final = NULL;
	q.cant = 0;
}


void crear_nodo(pnodo &nodo, int valor)
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



int quitar_cola(tcola &q)
{
	int extraido;
	pnodo sefue;
	if(cola_vacia(q))
		extraido = -1;
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


int primero_cola(tcola q)
{
	
	int ext;
	if(cola_vacia(q))
		ext = -1;
	else
	{
		ext = q.inicio->dato;
	}
	
	return ext;
}


int ultimo_cola(tcola q)
{
	int ext;
	if(cola_vacia(q))
		ext = -1;
	else
	{
		ext = q.final->dato;
	}
	return ext;
}


int termino_fibo(int t){
	int res;
	int i=2,t1=1,t2=1;
	tcola cola;
	pnodo nuevo;
			
	iniciar_cola(cola);
	
	if(t==1 || t==2)
		res=t1;
	else{
		crear_nodo(nuevo,t1);
		agregar_cola(cola,nuevo);
		crear_nodo(nuevo,t2);
		agregar_cola(cola,nuevo);
		
		while(i<t){
			//1 - 1*
			//1* - 2
			
			t2=quitar_cola(cola)+primero_cola(cola);
			
			crear_nodo(nuevo, t2);
			agregar_cola(cola,nuevo);
			i++;
		}
		
		res=ultimo_cola(cola);
	}
	return res;
}
