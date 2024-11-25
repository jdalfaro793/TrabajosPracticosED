/*

Desarrolle un algoritmo que aplique el TDA cola y sus operaciones básicas para convertir una cadena de caracteres que
almacena dígitos de un valor decimal a su correspondiente valor numérico. Para ello, tenga en cuenta que un valor
fraccionario puede expresarse mediante la siguiente ecuación:

0,5327 = 5x10-1 + 3x10-2 + 2x10-3 + 7x10-4


Para desarrollar la solución utilice el TDA cola implementado en el ejercicio 6
Nota: SUPONGA QUE LOS VALORES A CONVERTIR SIEMPRE TIENEN PARTE ENTERA CERO


*/



#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

const int MAX = 10;

typedef char tcad[MAX];

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

main()
{
	int i;
	tcad cade;
	tcola cola;
	float result=0.0;
	pnodo nuevo;
	
	
	iniciar_cola(cola);
	

	cout << "Ingrese cadena: ";
	fflush(stdin);
	gets(cade);

	
	for(i=0;i<strlen(cade);i++){
		if(cade[i]-'0'>=1 && cade[i]-'0'<=9){
			crear_nodo(nuevo,cade[i]-'0');
			agregar_cola(cola,nuevo);
		}
	}
	i=-1;
	while(!cola_vacia(cola)){
		
		result=result+ quitar_cola(cola)*pow(10,i);
		i--;
	}
	
	cout<<"result: "<<result<<endl;

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


