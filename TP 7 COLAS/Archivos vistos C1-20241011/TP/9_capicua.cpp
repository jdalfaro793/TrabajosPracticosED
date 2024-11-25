/*

TDA COLA CON ARREGLO QUE PRIORIZA VELOCIDAD DE PROCESAMIENTO

*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX = 20;

typedef char tcontenedor[MAX];

typedef struct tcola
{
	tcontenedor datos;
	int frente;
	int final;
};


void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, char nuevo);
bool cola_llena(tcola cola);
char quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
char primero_cola(tcola cola);
char ultimo_cola(tcola cola);
int siguiente(int indice);


bool capicua(tcontenedor cad);


main()
{
	tcontenedor cadena;
	cout<<"ingrese cadena"<<endl;
	fflush(stdin);
	gets(cadena);
	
	if(capicua(cadena))
		cout<<"es capicua"<<endl;
	else
		cout<<"no es capicua"<<endl;
}


//ops cola


void iniciar_cola(tcola &cola)
{
	cola.frente = 4;
	cola.final = 4;
}

void agregar_cola(tcola &cola, char  nuevo)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		cola.final = siguiente(cola.final);
		cola.datos[cola.final] = nuevo;
	}
}

bool cola_llena(tcola cola)
{
	bool r;
	r = siguiente(cola.final) == cola.frente;
	return r;
}

char  quitar_cola(tcola &cola)
{
	char  extraido;
	
	if(cola_vacia(cola))
		extraido = '@'; //valor arbitrario
	else
	{
		cola.frente = siguiente(cola.frente);
		extraido = cola.datos[cola.frente];
	}
	return extraido;
}

bool cola_vacia(tcola cola)
{
	bool r;
	r = cola.final == cola.frente;
	
	return r;
}

char  primero_cola(tcola cola)
{
	char  primero;
	if(cola_vacia(cola))
		primero = '@'; //valor arbitrario
	else
		primero = cola.datos[siguiente(cola.frente)];
	
	return primero;
}

char  ultimo_cola(tcola cola)
{
	char  ultimo;
	if(cola_vacia(cola))
		ultimo = '@'; //valor arbitrario
	else
		ultimo = cola.datos[cola.final];
	
	return ultimo;
}

int siguiente(int indice)
{
	
	if(indice == MAX - 1)
		indice = 0;
	else
		indice++;
	
	return indice;
}


bool capicua(tcontenedor cad){
	tcola cola;
	int i;
	bool impar,capicua=true;
	char a;
	
	iniciar_cola(cola);

	
	for(i=0;i<strlen(cad);i++){
			agregar_cola(cola,cad[i]);
	}
	
	for( i=strlen(cad)-1; i>=0&& capicua; i-- ){
		
		capicua= cad[i] == quitar_cola(cola);
	}
	
	return capicua;
	
}


