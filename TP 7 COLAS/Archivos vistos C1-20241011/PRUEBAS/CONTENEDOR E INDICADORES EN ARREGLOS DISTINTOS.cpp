/*

TDA COLA CON ARREGLO QUE PRIORIZA VELOCIDAD DE PROCESAMIENTO

*/

#include <iostream>

using namespace std;

const int MAXC = 10;
const int MAXI = 2;

typedef int tcontenedor[MAXC];
typedef int tindicadores[MAXI];


typedef struct tcola
{
    tcontenedor datos;
	tindicadores indice;
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
int cociente(int dividendo, int divisor);

main()
{
    tcola cola;
    int  nuevo, eliminado;
    int op, valor, extremo;
    iniciar_cola(cola);
	int dividendo,divisor,resultado=0;
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
		case 5:
			cout << "...........DIVISION CON COLAS.........." << endl;
			
			do{
				cout << "ingrese dividendo"<<endl;
				cin>>dividendo;
				cout << "ingrese divisor"<<endl;
				cin>>divisor;
				
				if(dividendo<1 || divisor<1)
					cout<<"deben ser valores positivos"<<endl;
			} while(dividendo<1 || divisor<1);

			cout<<"division es: "<<cociente(dividendo, divisor)<<endl;
			break;
        default :
            cout << " OPCION INCORRECTA" << endl;
        }
        system("pause");

    }
    while(op != 5);
}

void menu(int &opc)
{
    cout << "..........MENU.........." << endl;
    cout << "1- Agregar un elemento" << endl;
    cout << "2- Quitar un elemento" << endl;
    cout << "3- Mostrar frente y final" << endl;
    cout << "4- Salir" << endl;
	cout<< 	"5- Division con colas"<<endl;
    cout << "Elija una opcion: ";
    cin >> opc;
}

void iniciar_cola(tcola &cola)
{
	cola.indice[0]=MAXC-1; //FRENTE 
    cola.indice[1]=MAXC-1; //FINAL
}

void agregar_cola(tcola &cola, int nuevo)
{
    if(cola_llena(cola))
        cout << "cola llena" << endl;
    else
    {
        cola.indice[1] = siguiente(cola.indice[1]);
        cola.datos[cola.indice[1]] = nuevo;
    }
}

bool cola_llena(tcola cola)
{
    return siguiente(cola.indice[1]) == cola.indice[0];
}

int quitar_cola(tcola &cola)
{
    int extraido;

    if(cola_vacia(cola))
        extraido = -999999; //valor arbitrario
    else
    {
		cola.indice[0] = siguiente(cola.indice[0]);
        extraido = cola.datos[cola.indice[0]];
    }
    return extraido;
}


bool cola_vacia(tcola cola)
{
    return cola.indice[1] == cola.indice[0];
}

int primero_cola(tcola cola)
{
    int primero;
    if(cola_vacia(cola))
        primero = -999999; //valor arbitrario
    else
        primero = cola.datos[siguiente(cola.indice[0])];

    return primero;
}

int ultimo_cola(tcola cola)
{
    int ultimo;
    if(cola_vacia(cola))
        ultimo = -999999; //valor arbitrario
    else
        ultimo = cola.datos[cola.indice[1]];

    return ultimo;
}

int siguiente(int indice)
{

    if(indice == MAXC - 1)
        indice = 0;
    else
        indice++;

    return indice;
}


int cociente(int dividendo, int divisor){
	
	tcola cola;
	iniciar_cola(cola);
	int i=0;
	while(dividendo>0 && dividendo>=divisor){
		agregar_cola(cola, dividendo-divisor);
		dividendo=dividendo-divisor;
	}
	while(!cola_vacia(cola)){
		quitar_cola(cola);
		i=i+1;
	}
	
	
	return i;
}
