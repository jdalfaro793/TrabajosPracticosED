/*

la bicola prioriza el espacio de almacenamiento y se construye únicamente con un arreglo (20 elementos),
ubicando los indicadores en las posiciones iniciales del arreglo

SALIDA RESTRINGIDA

*/


#include <iostream>

using namespace std;

const int MAX = 20;

typedef int tcola[MAX];


void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, int nuevo, int tipo_ingreso);
bool cola_llena(tcola cola);
int  quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
int primero_cola(tcola cola);
int ultimo_cola(tcola cola);
int siguiente(int indice);
int anterior(int indice);
void menu(int &op);

main()
{
	tcola cola;
	int nuevo, eliminado, tipo_ingreso;
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
			
			
			do{
				cout<<"ingrese tipo ingreso: 1- frente , 2- final"<<endl;
				cin>>tipo_ingreso;
			} while(tipo_ingreso!=1 && tipo_ingreso!=2);
			agregar_cola(cola, nuevo, tipo_ingreso);
			
			
			break;
		case 2:
			cout << ".....Quitar valor ......" << endl;

			
			eliminado = quitar_cola(cola);
			if(eliminado != -1)
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
	cola[0] = MAX-1; 	//FRENTE
	cola[1] = MAX-1; 	//FINAL
	cola[2] = 0; 		//CONTADOR
}

void agregar_cola(tcola &cola, int  nuevo, int tipo_ingreso)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		if(tipo_ingreso==2){
			cola[1]=siguiente(cola[1]);
			cola[cola[1]]=nuevo;
			//frente
		}else{
			cola[0]=anterior(cola[0]);
			cola[siguiente(cola[0])]=nuevo;
			
		}
		cola[2]++;

	}
}

int  quitar_cola(tcola &cola)
{
	int  extraido;
	
	if(cola_vacia(cola))
		extraido = -1; //valor arbitrario
	else
	{	
		
		cola[0] = siguiente(cola[0]);
		
		extraido=cola[cola[0]];
		
		cola[2]--;

	}
	return extraido;
}



bool cola_llena(tcola cola)
{  
	return cola[2]==MAX-3;
}

bool cola_vacia(tcola cola)
{
	return cola[2]==0;
}



int  primero_cola(tcola cola)
{
	int  primero;
	if(cola_vacia(cola))
		primero = -1; //valor arbitrario
	else
	{	
		
		primero=cola[siguiente(cola[0])];
	}
	return primero;
}


int  ultimo_cola(tcola cola)
{
	int  ultimo;
	if(cola_vacia(cola))
		ultimo = -1; //valor arbitrario
	else{
		
		ultimo=cola[cola[1]];
	}
		return ultimo;
}


int siguiente(int indice){
	indice++;	
	
	if(indice==MAX)
		indice=3;
	
	return indice;
}

	
int anterior(int indice){
	indice--;
	
	if(indice==2)
		indice=MAX-1;

	return indice;
}
