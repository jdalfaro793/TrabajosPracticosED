#include <iostream>

using namespace std;

const int MAX = 20;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo sig;
};

typedef struct tcola{
	pnodo inicio;
	pnodo final;
	int cant;
};

void menu(int &op);
void iniciar_cola(tcola &q);
void crear_nodo(pnodo &nodo);
void agregar_cola(tcola &q, pnodo nuevo);
int quitar_cola(tcola &q);
bool cola_llena(tcola q);
bool cola_vacia(tcola q);
int primero_cola(tcola q);
int ultimo_cola(tcola q);

main(){
	
	int op, extraido;
	tcola cola;
	pnodo nuevo;
	
	
	iniciar_cola(cola);
	
	
	
	do{
		system("cls");
		menu(op);	
		
		switch(op){
		case 1:
			
				crear_nodo(nuevo);
			
				agregar_cola(cola,nuevo);
				
				break;
		case 2:
			
				extraido=quitar_cola(cola);
				
				if(extraido!=-1)
					cout<<"se quito: "<<extraido<<endl;
				else
					cout<<"cola vacia papá"<<endl;	
				
				break;
		case 3:
			
			if(!cola_vacia(cola)){
				cout<<"frente: "<<primero_cola(cola)<<endl;
				cout<<"final: "<<ultimo_cola(cola)<<endl;
			}else{
				cout<<"cola vacia papá"<<endl;
			}
			break;
			
		case 4:
			
			cout<<"fin del programa papito"<<endl;
			
			break;
			
		default:
			cout<<"error opcion invalida"<<endl;
		}
		
		system("pause");
	} while(op!=4);
	
	
	
	
	
}

void menu(int &op)
{
	cout << "..........MENU.........." << endl;
	cout << "1- Agregar un elemento" << endl;
	cout << "2- Quitar un elemento" << endl;
	cout << "3- Mostrar frente y final" << endl;
	cout << "4- Salir" << endl;
	cout << "Elija una opcion: ";
	cin >> op;
}

void iniciar_cola(tcola &q){
	q.inicio=NULL;
	q.final=NULL;
	q.cant=0;
}
	

void crear_nodo(pnodo &nodo){
	nodo=new tnodo;
	if(nodo!=NULL){
		cout<<"ingrese num: "<<endl;
		cin>>nodo->dato;
		nodo->sig=NULL;
	}else{
		cout<<"memoria insuficiente"<<endl;
	}
}

void agregar_cola(tcola &q, pnodo nuevo){
	if(cola_llena(q))
		cout<<"cola llena cdsm"<<endl;
	else{
		if(q.inicio==NULL){
			q.inicio=nuevo;
			q.final=nuevo;
		}else{
			q.final->sig=nuevo;
			q.final=nuevo;
		}
		q.cant++;
	}
	
}



int quitar_cola(tcola &q){
	int extraido;
	pnodo sefue;
	if(cola_vacia(q))
		extraido=-1;
	else{
		sefue=q.inicio;
		
		q.inicio=sefue->sig;
		
		extraido=sefue->dato;
		
		delete(sefue);
		
		q.cant--;
	}

	return extraido;
}


bool cola_llena(tcola q){

	return q.cant==MAX;

}
	
bool cola_vacia(tcola q){

	return q.cant==0;

}

	
int primero_cola(tcola q){

	int ext;
	if(cola_vacia(q))
		ext=-1;
	else{
		ext=q.inicio->dato;
	}

	return ext;
}

	
int ultimo_cola(tcola q){
	int ext;
	if(cola_vacia(q))
		ext=-1;
	else{
		ext=q.final->dato;
	}	
	return ext;
}

