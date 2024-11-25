#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};


typedef struct tlista{
	pnodo inicio;
	pnodo final;
	
	int cant_mayus;
	int cant_minus;
	int cant_simbolos;
	int cant_digitos;
};



void iniciar_lista(tlista &lista){
lista.inicio=NULL;
lista.final=NULL;
lista.cant_digitos=0;
lista.cant_mayus=0;
lista.cant_minus=0;
lista.cant_simbolos=0;
}


void crear_nodo(pnodo &nuevo){
	nuevo = new tnodo;
	
	if(nuevo!=NULL){
		cout<<"Ingrese caracter: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else{
		cout<<"Memoria insuficiente";
	}
}


void agregar_final(tlista &lista, pnodo nuevo){
	
	bool b1,b2,b3,b4;
	
	b1= (nuevo->dato>='a' && nuevo->dato<='z') && lista.cant_minus<5;
	b2= (nuevo->dato>='A' && nuevo->dato<='Z') && lista.cant_mayus<5;
	b3= (nuevo->dato>='0' && nuevo->dato<='9') && lista.cant_digitos<5;
	b4= !(nuevo->dato>='a' && nuevo->dato<='z') && !(nuevo->dato>='A' && nuevo->dato<='Z')&& !(nuevo->dato>='0' && nuevo->dato<='9') && lista.cant_simbolos<5;
	
	//validar espacio si no hay eliminar nodo
	if(b1) lista.cant_minus++;
	if(b2) lista.cant_mayus++;
	if(b3) lista.cant_digitos++;
	if(b4) lista.cant_simbolos++;
	
	if(b1 || b2 || b3 || b4){
		if(lista.inicio==NULL){
			lista.inicio=nuevo;
			lista.final=nuevo;
		}else{
			lista.final->sig=nuevo;
			lista.final=nuevo;
		}
		cout<<"Nodo agregado"<<endl;
	}else{
		cout<<"No se puede agregar este tipo de caracter, se eliminará el nodo."<<endl;
		delete (nuevo);
	}
}

pnodo quitar_inicio(tlista &lista){
	pnodo extraido;
	bool b1,b2,b3,b4;
	
	if(lista.inicio==NULL){
		extraido==NULL;
	}else{
		//unico dato
		if(lista.inicio==lista.final){
		 extraido=lista.inicio;
		 iniciar_lista(lista);
		 
		}else{
			extraido=lista.inicio;
			lista.inicio=lista.inicio->sig;
			extraido->sig=NULL;
			
			b1= (extraido->dato>='a' && extraido->dato<='z');
			b2= (extraido->dato>='A' && extraido->dato<='Z');
			b3= (extraido->dato>='0' && extraido->dato<='9');
			b4= !(extraido->dato>='a' && extraido->dato<='z') && !(extraido->dato>='A' && extraido->dato<='Z')&& !(extraido->dato>='0' && extraido->dato<='9');
			
			if(b1) lista.cant_minus--;
			if(b2) lista.cant_mayus--;
			if(b3) lista.cant_digitos--;
			if(b4) lista.cant_simbolos--;
		}
	}
	return extraido;
}
	
	
void mostrar_lista(tlista lista){
	pnodo i;
	if(lista.inicio==NULL){
		cout<<"lista vacia"<<endl;
	}else{
		
		for(i=lista.inicio; i!=NULL; i=i->sig){
			cout << "  " << i->dato;
		}
		cout<<"\nMayusculas: "<<lista.cant_mayus<<endl;
		cout<<"Minuscula: "<<lista.cant_minus<<endl;
		cout<<"Digitos: "<<lista.cant_digitos<<endl;
		cout<<"Simbolos: "<<lista.cant_simbolos<<endl;
	}
}

void menu(int &opc)
{
	cout << "----------------------------\n";
	cout << "*                          *\n";
	cout << "*  1. Agregar Final        *\n";
	cout << "*  2. Quitar Inicio        *\n";
	cout << "*  3. Mostrar Lista        *\n";
	cout << "*  4. Salir                *\n";
	cout << "*                          *\n";
	cout << "----------------------------\n";
	cout << "Seleccione una opcion: ";
	cin >> opc;
}
