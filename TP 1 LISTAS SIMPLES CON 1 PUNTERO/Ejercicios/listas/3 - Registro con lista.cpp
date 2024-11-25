#include <iostream>

using namespace std;

typedef struct tnodo *pnodo; //puntero
typedef struct tnodo{
	int dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo inicio;
	int impares;
	int pares;
};

void inicializar_lista(tlista &lis);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lis,pnodo nuevo,int limite);
pnodo quitar_inicio(tlista &list);
void mostrar_lista(pnodo inicio);
void menu(int &op);
bool isPar(int num);


main(){
	int opcion, limite=4;
	tlista lista;
	pnodo nuevo, eliminado;
	
	inicializar_lista(lista);
	
	do
	{
		system("cls");
		menu(opcion);
		switch(opcion)
		{
		case 1:
			cout << ".....Agregar Inicio ......" << endl;
			crear_nodo(nuevo);
			agregar_inicio(lista, nuevo, limite);
			mostrar_lista(lista.inicio);
			break;
			
		case 2:
			cout << ".....Quitar Final ......" << endl;
			eliminado = quitar_inicio(lista);
			
			if(eliminado != NULL)
			{
				cout << "Eliminado " << eliminado->dato << endl;
				delete(eliminado);
				mostrar_lista(lista.inicio);
			}
			else
			   cout << "No se puede eliminar, lista vacia" << endl;
			break;
		case 3:
			cout << "..........Mostrando Lista.........." << endl;
			mostrar_lista(lista.inicio);
			
			cout<<"\npares: "<<lista.pares<<endl;
			cout<<"impares: "<<lista.impares<<endl;
			cout << endl;
			break;
		case 4:
			cout << "...........FIN DEL PROGRAMA ~^.^~ ..........." << endl;
			break;
			
		default :
				cout << " OPCION INCORRECTA" << endl;
		}
		cout<<endl;
		system("pause");
	} while(opcion!=4);
}


void inicializar_lista(tlista &lis){

	lis.inicio=NULL;
	lis.pares=0;
	lis.impares=0;
}
	
	
void crear_nodo(pnodo &nuevo){
	cout<<"crear_nodo"<<endl;
	nuevo=new tnodo;
	if(nuevo!=NULL){
		cout<<"ingrese dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else{
		cout<<"memoria insuficiente"<<endl;
	}
}


void agregar_inicio(tlista &lis,pnodo nuevo,int limite){
	
	if((lis.impares+lis.pares)<limite) {
		
		if(lis.inicio==NULL){
			lis.inicio=nuevo;
		}else{
			nuevo->sig=lis.inicio;
			lis.inicio=nuevo;
		}
		
		if(isPar(nuevo->dato)){
			lis.pares++;
		}else{
			lis.impares++;
		}
		
	}else{
		cout<<"se alcanzo el limite de nodos: "<<lis.impares+lis.pares<<endl;
		delete(nuevo);
	}
}

pnodo quitar_inicio(tlista &list){
	
	pnodo extraido;
	
	if(list.inicio==NULL){
		extraido=NULL;
	}else{
		extraido=list.inicio;
		list.inicio=list.inicio->sig;
		extraido->sig=NULL;
	}
	
	if(isPar(extraido->dato)){
		list.pares--;
	}else{
		list.impares--;
	}
	
	return extraido;
}

bool isPar(int num){
	bool res = num%2==0;
	return res;
}

//recursivo
void mostrar_lista(pnodo inicio){
	if (inicio==NULL){
		cout << "Lista Vacia" << endl;
	} else {
		if (inicio->sig==NULL){
			cout << " "<<inicio->dato;
		} else { 
			cout << " "<<inicio->dato;
		
			mostrar_lista(inicio->sig);
		}
	}
}
	
void menu(int &op)
{
	cout << "****MENU****" << endl;
	cout << "1-Agregar Inicio" << endl;
	cout << "2-Quitar Inicio" << endl;
	cout << "3-Mostrar Lista" << endl;
	cout << "4-Salir" << endl;
	cout << "Elija opcion: ";
	cin >> op;
}

