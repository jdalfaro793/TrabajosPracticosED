/*

TDA COLA CON ARREGLO QUE PRIORIZA VELOCIDAD DE PROCESAMIENTO


vector:  |4|3|6|7| |1|2|3|4|5|
indices:  0 1 2 3 4 5 6 7 8 9

*/

#include <iostream>

using namespace std;

const int MAX = 10;

typedef int tcola[MAX];

void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, int nuevo);
bool cola_llena(tcola cola);
int quitar_cola(tcola &cola);
bool cola_vacia(tcola cola);
int primero_cola(tcola cola);
int ultimo_cola(tcola cola);
int siguiente(int posicion);
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
    cola[1]=4;//frente
    cola[0]=4;//final
}

bool cola_llena(tcola cola)
{
    return siguiente(cola[1]) == cola[0];
}

void agregar_cola(tcola &cola, int nuevo)
{
	if(cola_llena(cola))
		cout << "cola llena" << endl;
	else
	{
		
		cola[1] = siguiente(cola[1]);
		cola[cola[1]] = nuevo;
	}
}

int siguiente(int posicion)
{
	int sig;
	if(posicion == MAX - 1)
		sig = 2;
	else
		sig=posicion+1;
	
	return sig;
}

int quitar_cola(tcola &cola)
{
    int aux;

    if(cola_vacia(cola))
        aux = -999999; //valor arbitrario
    else
    {
        cola[0] = siguiente(cola[0]);
        aux = cola[cola[0]];
    }
    return aux;
}

bool cola_vacia(tcola cola)
{
    return cola[0]==cola[1];
}

int ultimo_cola(tcola cola)
{
    int aux;
    if(cola_vacia(cola))
        aux = -999999; //valor arbitrario
    else
        aux = cola[cola[1]];

    return aux;
}

int primero_cola(tcola cola)
{
	int primero;
	if(cola_vacia(cola))
		primero = -999999; //valor arbitrario
	else
		primero = cola[siguiente(cola[0])];
	
	/*
	cola[1]=4;//frente
	cola[0]=4;//final
	*/
	return primero;
}
