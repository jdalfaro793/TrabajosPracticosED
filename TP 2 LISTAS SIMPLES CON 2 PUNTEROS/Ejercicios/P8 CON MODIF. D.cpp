#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo inicio;
	pnodo final;
	int cant;
	
};


void menu(int &op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_en_orden(tlista &lista, pnodo nuevo);
void mostrar_lista(pnodo lista);
pnodo quitar_final(tlista &lista);

main() {
	tlista lista1;
	tlista lista2;
	
	iniciar_lista(lista1);
	iniciar_lista(lista2);
	
	pnodo nue,extraido;
	
	int tipolis,op;
	
	
	do{
		system("cls");
		menu(op);
		
		
		switch(op){
		case 1:
			crear_nodo(nue);
			
			do{
				cout<<"En que lista agregar? 1 ó 2: ";
				cin>>tipolis;
			} while(!(tipolis==1 || tipolis==2));
			
			
			if(tipolis==1){
				agregar_en_orden(lista1,nue);
			}else{
				agregar_en_orden(lista2,nue);
			}
		
			break;
			
		case 2: 
			
			do{
				cout<<"Que lista quiere quitar final? 1 ó 2: ";
				cin>>tipolis;
			} while(!(tipolis==1 || tipolis==2));
			
			
			if(tipolis==1){
				extraido=quitar_final(lista1);
			}else{
				extraido=quitar_final(lista2);
			}
			
			if(extraido!=NULL)
			cout<<"se extrajo el valor: "<<extraido->dato<<endl;
			else cout<<"Lista vacia..."<<endl;
			
			delete(extraido);
			
			break;
		case 3: 

			do{
				cout<<"Que lista mostrar? 1 ó 2: ";
				cin>>tipolis;
			} while(!(tipolis==1 || tipolis==2));
			
			
			if(tipolis==1){
				mostrar_lista(lista1.inicio);
				cout<<"cant. elementos: "<<lista1.cant<< endl;
			}else{
				mostrar_lista(lista2.inicio);
				cout<<"cant. elementos: "<<lista2.cant<< endl;
			}
			
			
			break;

		case 4:
			cout<<"fin.."<<endl;
			break;
			
		default: 
			cout<<"opc. invalida"<<endl;
			
		}
		
		system("pause");
	} while(op!=4);
	
	
}

void menu(int &op){
	cout<<"1- Agregar en orden"<<endl;
	cout<<"2- Quitar final"<<endl;
	cout<<"3- Mostrar lista"<<endl;
	cout<<"4- Salir"<<endl;	
	cout<<"\nIngrese opcion: ";
	cin>>op;
}
	
void iniciar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
	lista.cant=0;
}
	
	

	void crear_nodo(pnodo &nuevo){
		nuevo=new tnodo;
		
		if(nuevo!=NULL){
			cout<<"ingrese valor: ";
			cin>>nuevo->dato;
			nuevo->sig=NULL;
		}else{
			
			cout<<"memoria insuficiente..."<<endl;
			
		}
	}


void agregar_en_orden(tlista &lista, pnodo nuevo){
	pnodo i;
	
	//lista vacia
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{
		//evaluo extremo menor
		if(nuevo->dato <= lista.inicio->dato ){
			nuevo->sig = lista.inicio;
			lista.inicio=nuevo;
		}else{
			//evaluo extremo mayor
			if(nuevo->dato >= lista.final->dato){
				lista.final->sig=nuevo;
				lista.final=nuevo;
			}else{
				//evaluar posicion
				for(i=lista.inicio; i!=NULL && (i->sig)->dato < nuevo->dato; i=i->sig);
				
				nuevo->sig=i->sig;
				i->sig=nuevo;
				
			}
		}
	}
	lista.cant++;
}
	
	pnodo quitar_final(tlista &lista){
		pnodo extraido,i;
		
		if(lista.inicio==NULL){
			extraido=NULL;
			

		}else{
			if(lista.inicio->sig==NULL){
				
				extraido=lista.inicio;
				
				iniciar_lista(lista);
				
			}else{
				for(i=lista.inicio ; i!=NULL && (i->sig)->sig!=NULL; i=i->sig);
				
				extraido=i->sig;
				i->sig=NULL;
				lista.cant--;
				
			}
		}
		
		return extraido;
	}
	
	void mostrar_lista(pnodo lista){
		if(lista==NULL){
			cout<<"lista vacia..."<<endl;
		}else{
			if(lista->sig==NULL){
				cout<<lista->dato<<" ";
			}else{
				cout<<lista->dato<<" ";
				mostrar_lista(lista->sig);
			}
			
		}
		cout<<endl;
	}
