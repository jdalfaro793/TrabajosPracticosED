/*

Suponiendo que la definición del tamaño de arreglos está restringida a 5 elementos, modifique la implementación
(definición de la estructura y operaciones) que prioriza espacio de almacenamiento de modo que se pueda construir
colas de 15 elementos. ¿Cómo se modificaría esta implementación si las últimas posiciones del primer arreglo se utilizan
para almacenar los indicadores de la cola? ¿Cuántos datos podrán almacenarse en esta segunda implementación?

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX = 5;

typedef int tcontenedor[MAX];

typedef struct tcola
{
	tcontenedor datos1;
	tcontenedor datos2;
	tcontenedor datos3;
	
	int frente;
	int final;
	int cantidad;
};


void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, int nuevo);
bool cola_llena(tcola cola);
int quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
int primero_cola(tcola cola);
int ultimo_cola(tcola cola);
int siguiente(int indice);
void menu(int &op);

main()
{
	tcola cola;
	int  nuevo, eliminado;
	int op, valor, extremo;
	iniciar_cola(cola);
	do
	{
		system("cls");
		menu(op);
		
		switch(op)
		{
		case 1:
			
				cout << ".....Agregar valor ......" << endl;
				cin >> nuevo;
				agregar_cola(cola, nuevo);				


			break;
		case 2:
			cout << ".....Quitar valor ......" << endl;
			eliminado = quitar_cola(cola);
			if(eliminado != -999999)
				cout << "se eliminó: " << eliminado << endl;
			else
				cout << "cola vacia" << endl;
			break;
			
		case 3:
			cout << ".....Ver valores de los extremos......" << endl;
			if(cola_vacia(cola) != true)
			{
				cout << "Frente: " << primero_cola(cola) << endl;
				cout << "Final: " << ultimo_cola(cola) << endl;
			}
			else
			   cout << "cola vacia" << endl;
			break;
		case 4:
			cout << "...........FIN DEL PROGRAMA..........." << endl;
			break;
			default :
				cout << " OPCION INCORRECTA" << endl;
		}
		system("pause");
		
	}
	while(op != 4);
}

void menu(int &opc)
{
	cout << "..........MENU.........." << endl;
	cout << "1- Agregar un elemento" << endl;
	cout << "2- Quitar un elemento" << endl;
	cout << "3- Mostrar frente y final" << endl;
	cout << "4- Salir" << endl;
	cout << "Elija una opcion: ";
	cin >> opc;
}

void iniciar_cola(tcola &cola)
{
	cola.frente = 0;
	cola.final = 0;
	cola.cantidad=0;
}

void agregar_cola(tcola &cola, int nuevo)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		cola.final = siguiente(cola.final);
		
		if(cola.final<=MAX-1)
			cola.datos1[cola.final] = nuevo;
		else{
			if(cola.final<=2*MAX-1)
				cola.datos2[cola.final-MAX]=nuevo;
			else
				cola.datos3[cola.final-(2*MAX)]=nuevo;
		}
		cola.cantidad++;
	}
}

bool cola_llena(tcola cola)
{
	return cola.cantidad == MAX*3; //siguiente(cola.final) == cola.frente;
}

int quitar_cola(tcola &cola)
{
	int extraido;
	
	if(cola_vacia(cola))
		extraido = -999999; //valor arbitrario
	else
	{
		cola.frente = siguiente(cola.frente);
		if(cola.frente<MAX)
			extraido=cola.datos1[cola.frente];
		else if(cola.frente<2*MAX)
			extraido = cola.datos2[cola.frente-MAX];
		else
			extraido=cola.datos3[cola.frente-2*MAX];
		
		cola.cantidad--;
	}
	return extraido;
}

bool cola_vacia(tcola cola)
{
	return cola.cantidad==0;
}

int primero_cola(tcola cola)
{
	int primero;
	if(cola_vacia(cola))
		primero = -999999; //valor arbitrario
	else{
		primero = cola.datos1[siguiente(cola.frente)];
	}
	return primero;
}

int ultimo_cola(tcola cola)
{
	int ultimo;
	if(cola_vacia(cola))
		ultimo = -999999; //valor arbitrario
	else{

		if(cola.final<MAX)
			ultimo = cola.datos1[cola.final];
		else {
			if(cola.final<2*MAX){
				ultimo=cola.datos2[cola.final-MAX];
			}else{
				ultimo=cola.datos3[ cola.final- (2*MAX)];		
			}
		}
	}
	
	return ultimo;
}

int siguiente(int indice)
{
	
	if(indice == ((3*MAX) - 1) )
		indice = 0;
	else
		indice++;
	
	return indice;
}


