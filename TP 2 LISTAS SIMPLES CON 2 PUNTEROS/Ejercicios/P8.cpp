#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};

typedef pnodo tlista[2];


void menu(int &op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_en_orden(pnodo &lista, pnodo nuevo);
void mostrar_lista(pnodo lista);
pnodo quitar_final(pnodo &lista);

main() {
	tlista lista;
	
	iniciar_lista(lista);
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
				agregar_en_orden(lista[0],nue);
			}else{
				agregar_en_orden(lista[1],nue);
			}
		
			break;
			
		case 2: 
			
			do{
				cout<<"Que lista quiere quitar final? 1 ó 2: ";
				cin>>tipolis;
			} while(!(tipolis==1 || tipolis==2));
			
			
			if(tipolis==1){
				extraido=quitar_final(lista[0]);
			}else{
				extraido=quitar_final(lista[1]);
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
				mostrar_lista(lista[0]);
			}else{
				mostrar_lista(lista[1]);
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
	lista[0]=NULL;
	lista[1]=NULL;
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


void agregar_en_orden(pnodo &lista, pnodo nuevo){
	pnodo i;
	
	//lista vacia
	if(lista==NULL){
		lista=nuevo;
	}else{ 

			//evaluo extremo menor
			if( nuevo->dato<lista->dato ){
				nuevo->sig = lista;
				lista=nuevo;
			}else{
				

					//evaluar posicion
					for(i=lista; i!=NULL && (i->sig)->dato < nuevo->dato  ; i=i->sig);
					
					nuevo->sig=i->sig;
					i->sig=nuevo;
				
				
			}
	

		
	}
}
	
	pnodo quitar_final(pnodo &lista){
		pnodo extraido,i;
		
		if(lista==NULL){
			extraido=NULL;
			

		}else{
			if(lista->sig==NULL){
				extraido=lista;
				lista=NULL;
			}else{
				for(i=lista;i!=NULL && (i->sig)->sig!=NULL; i=i->sig);
				
				extraido=i->sig;
				i->sig=NULL;
				
				
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
