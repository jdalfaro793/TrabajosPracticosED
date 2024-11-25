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
void agregar_cola(tcola &cola, int nuevo);
bool cola_llena(tcola cola);
int quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
int primero_cola(tcola cola);
int ultimo_cola(tcola cola);
int siguiente(int indice);


int inverso_num(int n);


main()
{
	int num;

	cout<<"ingrese num"<<endl;
	cin>>num;
	
	cout<<"inverso num: "<<inverso_num(num)<<endl;
}

//ops cola


void iniciar_cola(tcola &cola)
{
	cola.frente = 4;
	cola.final = 4;
}

void agregar_cola(tcola &cola, int  nuevo)
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

int  quitar_cola(tcola &cola)
{
	int	  extraido;
	
	if(cola_vacia(cola))
		extraido = -1; //valor arbitrario
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

int primero_cola(tcola cola)
{
	int  primero;
	if(cola_vacia(cola))
		primero = -1; //valor arbitrario
	else
		primero = cola.datos[siguiente(cola.frente)];
	
	return primero;
}

int ultimo_cola(tcola cola)
{
	int  ultimo;
	if(cola_vacia(cola))
		ultimo = -1; //valor arbitrario
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


int inverso_num(int n){
	tcola cola;
	
	int i=0,multi=1,res=0;
	
	iniciar_cola(cola);

	while(n>0){
		agregar_cola(cola,n%10);
		n=n/10;
		i++;
	}
	
	while(i>1){
		multi=multi*10;
		i--;
	}
	
	while(!cola_vacia(cola)){
		res=res+multi*quitar_cola(cola);
		multi=multi/10;
	}
	return res;
}
	
	
	
