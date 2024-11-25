#include <iostream>

using namespace std;



typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
};


void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(pnodo &lista, pnodo nuevo);
pnodo quitar_final(pnodo &lista);
void mostrar_lista(pnodo lista);
bool buscar_valor(pnodo lista, int buscado);
void menu(int &op);

void agregar_final(pnodo &inicio, pnodo nuevo);

main() {
	pnodo lista, nue, extraido;
	int valor,op;
	iniciar_lista(lista);
	
	
	do{
		system("cls");
		menu(op);
		
		
		switch(op){
		case 1:
			crear_nodo(nue);
			
			agregar_inicio(lista,nue);
			
			break;
			
		case 2: 
			extraido=quitar_final(lista);

			
			if(extraido!=NULL)
			   cout<<"se extrajo el valor: "<<extraido->dato<<endl;
			else cout<<"Lista vacia..."<<endl;
			
			delete(extraido);
			
			break;
		case 3: 
				mostrar_lista(lista);

			
			break;
			
		case 4:
			
			cout<<"ingrese valor a buscar: "<<endl;
			cin>>valor;
			if(buscar_valor(lista,valor)) 
				cout<<"Se encontro el valor en la lista"<<endl;
			else
				cout<<"No existe el valor en la lista"<<endl;
			
			break;
			
		case 5:
			cout<<"fin.."<<endl;
			break;
		case 6:
			crear_nodo(nue);
			
			agregar_final(lista,nue);
			
			break;
		default: 
			cout<<"opc. invalida"<<endl;
			
		}
		
		system("pause");
	} while(op!=5);
	
	
}

void menu(int &op){
	cout<<"1- Agregar inicio"<<endl;
	cout<<"2- Quitar final"<<endl;
	cout<<"3- Mostrar lista"<<endl;
	cout<<"4- Buscar valor"<<endl;	
	cout<<"6- Agregar final"<<endl;	
	cout<<"5- Salir"<<endl;	
	cout<<"\nIngrese opcion: ";
	cin>>op;
}
	




void iniciar_lista(pnodo &lista){
	lista=NULL;
}

void crear_nodo(pnodo &nuevo){
	nuevo=new tnodo;
	
	if(nuevo!=NULL){
		cout<<"Ingrese valor: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else{
		cout<<"Memoria insuficiente..."<<endl;
	}
}
	


void agregar_inicio(pnodo &lista, pnodo nuevo){
	pnodo i;
	
	if(lista==NULL){
		// Si la lista está vacía, el nuevo nodo apunta a sí mismo, formando el ciclo
		lista=nuevo;
		lista->sig=nuevo;
	}else{
		// Apuntamos al nuevo nodo al primer nodo de la lista
		nuevo->sig=lista;
		
		// Buscamos el último nodo de la lista, cuyo siguiente es el primer nodo
		for(i=lista; i->sig!=lista; i=i->sig);
		
			
		// El último nodo ahora debe apuntar al nuevo nodo
		i->sig=nuevo;
		
		// Actualizamos la referencia a lista para que apunte al nuevo nodo
		lista=nuevo;		
		
	}
	
}
	
	
	void agregar_final(pnodo &inicio, pnodo nuevo){
		pnodo i;
		bool encontrado=false;
		
		if(inicio==NULL){
			inicio=nuevo;
			inicio->sig=inicio;
		}else{
			
			
				if(inicio->dato==nuevo->dato) 
					encontrado=true;
				else
				for(i=inicio;i->sig!=inicio && !encontrado; i=i->sig)
					if(i->sig->dato==nuevo->dato)
						encontrado = true;
				
			
			
			
				
			if(encontrado==true){
				cout<<"el nodo ya existe, eliminando"<<endl;
				delete(nuevo);
			}else{
				

				
				for(i=inicio;i->sig!=inicio; i=i->sig);
				i->sig=nuevo;
				nuevo->sig=inicio;
				
			}
			

			
		}
		
	}	
	
pnodo quitar_final(pnodo &lista){
	pnodo extraido,i;
	
	if(lista==NULL){
		extraido=NULL;
	}else{
		
		if(lista==lista->sig){
			extraido=lista;
			lista=NULL;
		}else{
			for(i=lista; (i->sig)->sig !=lista;i=i->sig);
			
			extraido=i->sig;
			extraido->sig=NULL;
			
			
			i->sig=lista;
		};
		
	}
	
	return extraido;
}
	

	void mostrar_lista(pnodo lista){
	pnodo i;

	if(lista==NULL) 
		cout<<"lista vacia..."<<endl;
	else{
			cout<< lista->dato<<" ";			
			for(i=lista;i->sig!=lista;i=i->sig){
				cout<<i->sig->dato<<" ";
			}
			
		}
		cout<<endl;
	}



bool buscar_valor(pnodo lista, int buscado){
	bool encontrado = false;
	pnodo i;
	
	if(lista->dato==buscado){
		encontrado=true;
	}else{
		for(i=lista;i->sig!=lista && !encontrado;i=i->sig){
			if((i->sig)->dato==buscado){
				encontrado=true;
			}
		}
	}
	
	return encontrado;
}
