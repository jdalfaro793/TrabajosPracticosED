#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	float dato;
	pnodo sig;
};


typedef struct tlista{
	pnodo inicio;
	pnodo final;
};



void iniciar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
}


void crear_nodo(pnodo &nuevo){
	nuevo = new tnodo;
	
	if(nuevo!=NULL){
		cout<<"Ingrese valor real: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else{
		cout<<"Memoria insuficiente";
	}
}

	
void agregar_inicio(tlista &lista, pnodo nuevo){
	//lista vacia
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{
		//lista con elementos
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
	}
}

void agregar_final(tlista &lista, pnodo nuevo){
	//lista vacia
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{
		//lista con elementos
		lista.final->sig=nuevo;
		lista.final=nuevo;
	}
}

bool existe_nodo(tlista li, float valor){
	pnodo i;
	bool encontrado=false;
	
	for(i=li.inicio; i!=NULL && !encontrado; i=i->sig){
		if(i->dato==valor){
			encontrado=true;
		}
	}
	
	return encontrado;
}

//opc 1= agregar_inicio - 2= agregar_final
void agregar_nodo_opcion(tlista &li, pnodo nuevo, int opc){
	if(!existe_nodo(li,nuevo->dato)){
		switch(opc){
			case 1: agregar_inicio(li,nuevo); break;
			case 2: agregar_final(li, nuevo); break;
			default: cout<<"error de opcion"<<endl;
		}
	}else{
		cout<<"el nodo ya existe en la lista, liberando memoria."<<endl;
		delete(nuevo);
	}
}


pnodo quitar_inicio(tlista &lista){
	pnodo extraido;
	
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
			
		}
	}
	return extraido;
}
	
	
pnodo quitar_final(tlista &lista){
	pnodo extraido,i;
	
	if(lista.inicio==NULL){
		extraido==NULL;
	}else{
		//unico dato
		if(lista.final==lista.inicio){
			extraido=lista.final;
			iniciar_lista(lista);
		}else{
			
			for(i=lista.inicio; i!=NULL && (i->sig)->sig!=NULL; i=i->sig);
			extraido=lista.final;
			lista.final=i;
			lista.final->sig=NULL;
		}
	}
	return extraido;
}

	
//opc 1= quitar_inicio - 2= quitar_final
void quitar_nodo_opcion(tlista &li, int opc){
	pnodo extraido;

		switch(opc){
			case 1: 
				extraido=quitar_inicio(li); 
				break;
			case 2: 
				extraido=quitar_final(li);
				break;
			default: cout<<"error de opcion"<<endl;
		}
		if(extraido!=NULL){
			cout<<"se extrajo el nodo: "<<extraido->dato<<endl;
			delete(extraido);
		}
}
		
	
void mostrar_lista(tlista lista){
	pnodo i;
	if(lista.inicio==NULL){
		cout<<"lista vacia"<<endl;
	}else{
		
		for(i=lista.inicio; i!=NULL; i=i->sig){
			cout << "  " << i->dato;
		}
	}
}

void menu(int &opc)
{
	cout << "----------------------------\n";
	cout << "*                          *\n";
	cout << "*  1. Agregar              *\n";
	cout << "*  2. Quitar               *\n";
	cout << "*  3. Mostrar              *\n";
	cout << "*  4. Salir                *\n";
	cout << "*                          *\n";
	cout << "----------------------------\n";
	cout << "Seleccione una opcion: ";
	cin >> opc;
}
