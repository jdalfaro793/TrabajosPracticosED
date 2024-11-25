#include <iostream>

using namespace std;

typedef struct tnodo *pnodo; //puntero
typedef struct tnodo
{
    float dato;
    pnodo sig;
};

void iniciar_lista (pnodo &lista);
void crear_nodo (pnodo &nuevo);
void agregar_inicio (pnodo &lista, pnodo nuevo);
float sumar_valores(pnodo inicio);
void determinar_maximo_lista(pnodo inicio);
pnodo buscar_nodo(pnodo lista, float valor);
void mostrar_lista(pnodo inicio);

void menu(char &op);

main()
{
	char opc;
	pnodo lista;
	pnodo nuevo, eliminado;
	
	iniciar_lista(lista);
	
	do
	{
		menu(opc);
		
		switch(opc){
			case 'a': 
				crear_nodo(nuevo);
				agregar_inicio(lista,nuevo);
				mostrar_lista(lista);
				cout<<endl;
				break;
			case 'b':
				
				if(lista==NULL)
					cout<<"lista es vacia"<<endl;
				else
					cout<<"suma total es: "<<sumar_valores(lista);
				cout<<endl;
				break;
			case 'c': 
				determinar_maximo_lista(lista);
				break;
			case 'd': 
				mostrar_lista(lista);
				cout<<endl;
				break;
			case 'e':
				cout<<"Fin..."<<endl;
				break;
		}
		
	} while(opc!='e');
   
}


void iniciar_lista (pnodo &lista)
{
	lista=NULL;
}

void agregar_inicio (pnodo &lista, pnodo nuevo){
	
	if(buscar_nodo(lista,nuevo->dato)==NULL){
		if(lista==NULL)
			lista=nuevo;
		else
		{
			nuevo->sig=lista;
			lista=nuevo;
		}		
	}else{
		cout<<"valor ya se encuentra agregado en la lista"<<endl;
		delete(nuevo);
		nuevo=NULL;
	}
}

void crear_nodo(pnodo &nuevo)
{
    cout << "crear_nodo" << endl;
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
		cout << "ingrese dato: ";
		cin >> nuevo->dato;
		nuevo->sig = NULL;
    }
    else
    {
		cout << "memoria insuficiente" << endl;
    }
}

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

pnodo buscar_nodo(pnodo lista, float valor){
	pnodo i=NULL;
	
	if(lista!=NULL){
		for(i=lista;i!=NULL && i->dato!=valor;i=i->sig);
	}
	
	return i;
}

void menu(char &op)
{
	cout << "****MENU****" << endl;
	cout << "a-Agregar inicio" << endl;
	cout << "b-Sumar valores" << endl;
	cout << "c-Determinar valor maximo" << endl;
	cout << "d-Mostrar recursivo" << endl;
	cout << "e-Salir" << endl;
	cout << "Elija opcion: ";
	cin >> op;
}

float sumar_valores(pnodo inicio){
	
	pnodo i=NULL;
	float suma=0;
	
	if(inicio!=NULL){
		for(i=inicio;i!=NULL;i=i->sig){
			suma=suma + (i->dato);
		}
	}
	
	return suma;
}
	
void determinar_maximo_lista(pnodo inicio){
	pnodo i;
	float maximo=0;
	if(inicio!=NULL){
		
		i=inicio;
		while(i!=NULL){
			if(maximo<i->dato)
				maximo=i->dato;
			   
			i=i->sig;
		}
		cout<<"el maximo de la lista es: "<<maximo<<endl;
	}else{
		cout << "Lista Vacia" << endl;
	}
}
