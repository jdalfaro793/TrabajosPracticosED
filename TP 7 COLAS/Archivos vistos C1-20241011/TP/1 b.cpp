/*

TDA COLA CON ARREGLO QUE PRIORIZA  ESPACIO DE ALMACENAMIENTO EN MEMORIA

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX = 10;

typedef char tcontenedor[MAX];

typedef struct tcola
{
	tcontenedor datos;
	int frente;
	int final;
	int cantidad;
};


void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, char nuevo);
bool cola_llena(tcola cola);
char quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
char primero_cola(tcola cola);
char ultimo_cola(tcola cola);
int siguiente(int indice);
void menu(int &op);

main()
{
	tcola cola;
	char  nuevo, eliminado;
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
			
			if(nuevo>='0' && nuevo<='9')
				agregar_cola(cola, nuevo);
			else
				cout<<"Caracter no es numero"<<endl;
			
			break;
		case 2:
			cout << ".....Quitar valor ......" << endl;
			eliminado = quitar_cola(cola);
			if(eliminado != '@')
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
	cola.frente = 4;
	cola.final = 4;
	cola.cantidad=0;
}

void agregar_cola(tcola &cola, char nuevo)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		cola.final = siguiente(cola.final);
		cola.datos[cola.final] = nuevo;
		cola.cantidad++;
	}
}

bool cola_llena(tcola cola)
{
	bool r;
	r =  cola.cantidad == MAX; //siguiente(cola.final) == cola.frente;
	return r;
}

char quitar_cola(tcola &cola)
{
	char extraido;
	
	if(cola_vacia(cola))
		extraido = '@'; //valor arbitrario
	else
	{
		cola.frente = siguiente(cola.frente);
		extraido = cola.datos[cola.frente];
		cola.cantidad--;
	}
	return extraido;
}

bool cola_vacia(tcola cola)
{
	bool r;
	r = cola.cantidad==0;
	
	return r;
}

char primero_cola(tcola cola)
{
	char primero;
	if(cola_vacia(cola))
		primero = '@'; //valor arbitrario
	else
		primero = cola.datos[siguiente(cola.frente)];
	
	return primero;
}

char ultimo_cola(tcola cola)
{
	char ultimo;
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


