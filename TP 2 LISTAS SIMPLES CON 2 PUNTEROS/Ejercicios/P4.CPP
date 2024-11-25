#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo inicio;
	pnodo final;
};


void menu(int &op);
void inicializar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista, pnodo nuevo);
void ver_repetidos(tlista &lista);
void ver_lista(pnodo inicio, pnodo final);
void invertir_lista(tlista &lista);
void copiar_lista(tlista &lista, tlista &copia);

pnodo getAnterior(pnodo inicio, pnodo fin);
main(){
	
	tlista li,co;
	pnodo nue;
	int op;
	inicializar_lista(li);
	inicializar_lista(co);
	
	do{
		system("cls");
		menu(op);
		
		
		switch(op){
		case 1:
			crear_nodo(nue);
			agregar_inicio(li,nue);
			cout<<"nodo agregado"<<endl;
			
			break;
		
		case 2: ver_repetidos(li); break;
		case 3: invertir_lista(li);break;
		case 4: copiar_lista(li,co);break;
		case 5: 
			
			ver_lista(li.inicio, li.final);
			if(co.inicio!=NULL){
				cout<<endl;
				ver_lista(co.inicio, co.final);
			}
			break;
		
		case 6: cout<<"fin.."<<endl;break;
		
		
		default: cout<<"opc. invalida"<<endl;
			
			
		
		}
		
		system("pause");
	} while(op!=6);
	
}


void menu(int &op){
	cout<<"1- Agregar inicio"<<endl;
	cout<<"2- Buscar valores repetidos"<<endl;
	cout<<"3- Invertir el contenido de la lista"<<endl;
	cout<<"4- Crear una copia de la lista"<<endl;
	cout<<"5- Ver listas"<<endl;
	cout<<"6- Salir"<<endl;	
	cin>>op;
}
	
	
	
void inicializar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
}


void crear_nodo(pnodo &nuevo){
	nuevo= new tnodo;
	if(nuevo!=NULL){
		
		cout<<"Ingrese valor: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
		
	}else{
		cout<<"Memoria insuficiente"<<endl;
	}
}
	
void agregar_inicio(tlista &lista, pnodo nuevo){
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
	}
}
	
void ver_repetidos(tlista &lista){
	pnodo i,j;
	int cont;
	if(lista.inicio!=NULL ){
		//validar mas de 2 nodos
		if(lista.inicio!=lista.final){
			for (i=lista.inicio	; i != NULL && i->sig != NULL; i=i->sig){
				cont=1;
				 for(j=i->sig; j!=NULL ; j=j->sig){
					if(i->dato==j->dato) cont++;
				 }
				 if(cont>1)
					 cout<<"Nodo con valor: "<<i->dato <<" se repite: "<<cont<< " veces"<<endl;
			}
		}else{
			cout<<"Es unico nodo, no tiene repetidos.."<<endl;
		}
	}else{
		cout<<"Lista vacia para buscar repetidos"<<endl;
	}	
}
	
	

	void invertir_lista(tlista &lista) {
		pnodo i;
		tlista aux;
		aux.inicio = NULL;  // Inicializamos la lista auxiliar vacía
		aux.final = NULL;
		
		if (lista.inicio != NULL) {
			if (lista.inicio == lista.final) {
				cout << "Lista con un solo elemento" << endl;
			} else {
				for (i = lista.final; i != NULL; i = getAnterior(lista.inicio, i)) {
					// Creamos un nuevo nodo para la lista invertida
					pnodo nuevoNodo = new tnodo;
					nuevoNodo->dato = i->dato;  // Copiamos el dato del nodo actual
					nuevoNodo->sig = NULL;
					
					if (aux.inicio == NULL) {
						// Primer nodo en la lista invertida
						aux.inicio = nuevoNodo;
						aux.final = nuevoNodo;
					} else {
						// Insertamos el nodo al principio de la lista invertida
						aux.final->sig=nuevoNodo;
						aux.final=nuevoNodo;
					}
				}
				// Reasignamos los punteros de la lista original
				lista = aux;
			}
		} else {
			cout << "Lista vacía" << endl;
		}
	}
	
	
	
pnodo getAnterior(pnodo inicio, pnodo fin){
	pnodo i;
	
	if(inicio==fin)return NULL;
	
	for(i=inicio;i->sig!=fin;i=i->sig);
	
	return i;
}
	
void ver_lista(pnodo inicio, pnodo final){
	if(inicio==NULL) cout<<"Lista vacia"<<endl;
	else{
		if(inicio==final)
			cout<<inicio->dato <<" ";
		else{
			cout<<inicio->dato <<" ";
			ver_lista(inicio->sig,final);
			}
		
	}
	cout<<endl;
}

	
	void copiar_lista(tlista &lista, tlista &copia){
		pnodo i;
		inicializar_lista(copia);
		
		if(lista.inicio!=NULL){
			
			for(i=lista.inicio;i!=lista.final->sig;i=i->sig){
				
				if(copia.inicio==NULL){
					copia.inicio=i;
					copia.final=i;
				}else{
					
					copia.final->sig=i;
					copia.final=i;
				}
			}
			
			cout<<"lista copia: "<<endl;
			
			ver_lista(copia.inicio, copia.final);
		}
	}
