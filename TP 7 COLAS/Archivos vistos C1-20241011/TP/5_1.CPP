#include <iostream>

using namespace std;

const int MAX=15;

typedef int tcola[MAX];

void iniciar_cola(tcola &q);

void agregar_cola(tcola &q, int nuevo);

int anterior(int indice);

bool cola_vacia(tcola q);

bool cola_llena(tcola q);

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
		//	eliminado = quitar_cola(cola);
			if(eliminado != -1)
				cout << "se eliminó: " << eliminado << endl;
			else
				cout << "cola vacia" << endl;
			break;
			
		case 3:
			cout << ".....Ver valores de los extremos......" << endl;
			if(cola_vacia(cola) != true)
			{
				for(int i=0;i<MAX;i++)
					cout<<cola[i]<< " ";
				//cout << "Frente: " << primero_cola(cola) << endl;
				//cout << "Final: " << ultimo_cola(cola) << endl;
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

void iniciar_cola(tcola &q){
	q[MAX/2-1]=0;//frente
	q[MAX/2]=0;//final 
	q[MAX/2+1]=0;//contador
}


bool cola_llena(tcola q){
	return q[MAX/2+1]==MAX-3;
}
	
void agregar_cola(tcola &q, int nuevo){
	
	if(cola_llena(q)){
		cout<<"cola llena"<<endl;
	}else{
		q[MAX/2] = anterior(q[MAX/2]);
		
		q[q[MAX/2]]=nuevo;
		
		
		q[MAX/2+1]++;
	}
	
}

int anterior(int indice){
	if(indice==0)
		return MAX-1;
	else{
		
		indice--;
		if(indice==MAX/2+1)
			indice=indice-3;
	}
	return indice;
}

bool cola_vacia(tcola q){
	return q[MAX/2-1] == q[MAX/2+1];
}

	
	
