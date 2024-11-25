/*

ÚNICAMENTE cuenta con 2 arreglos de 10
posiciones (cada uno) para construir el TDA. Utilice las posiciones iniciales del primer arreglo para almacenar los
indicadores de la cola.

*/

#include <iostream>

using namespace std;

const int MAX = 10;

typedef int tcontenedor[MAX];

typedef struct tcola
{
	tcontenedor datos1;
	tcontenedor datos2;
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
	int nuevo, eliminado;
	int op;
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
	cola.datos1[0] = MAX-1; //FRENTE
	cola.datos1[1] = MAX-1; //FINAL
}

void agregar_cola(tcola &cola, int  nuevo)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		cola.datos1[1]=siguiente(cola.datos1[1]);
		
		if(cola.datos1[1] <= MAX-1)
			cola.datos1[cola.datos1[1]]=nuevo;
		else{
			cola.datos2[ cola.datos1[1] - MAX ]=nuevo;
		}
		
	}
}

bool cola_llena(tcola cola)
{  
	return siguiente(cola.datos1[1]) ==  cola.datos1[0];
}

int  quitar_cola(tcola &cola)
{
	int  extraido;
	
	if(cola_vacia(cola))
		extraido = -1; //valor arbitrario
	else
	{
		cola.datos1[0] = siguiente(cola.datos1[0]);
		if( cola.datos1[0] <=MAX-1 )
			extraido=cola.datos1[0];
		else
			extraido = cola.datos2[cola.datos1[0]-MAX];
	}
	return extraido;
}

bool cola_vacia(tcola cola)
{
	return cola.datos1[1]==cola.datos1[0];
}

int  primero_cola(tcola cola)
{
	int  primero;
	if(cola_vacia(cola))
		primero = -1; //valor arbitrario
	else
		primero = cola.datos1[siguiente(cola.datos1[0])];
	
	return primero;
}

int  ultimo_cola(tcola cola)
{
	int  ultimo;
	if(cola_vacia(cola))
		ultimo = -1; //valor arbitrario
	else
		if(cola.datos1[1]<=MAX-1)
		ultimo=cola.datos1[cola.datos1[1]];
		else
		ultimo = cola.datos2[cola.datos1[1]-MAX];
	
	return ultimo;
}

int siguiente(int indice)
{
	if(indice == 2*MAX-1)
		indice = 2;
	else
		indice++;	
	return indice;
}
