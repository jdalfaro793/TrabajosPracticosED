#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef char tcad[20];

typedef struct tnodo *pnodo;

typedef struct tnodo{
	pnodo sig;
	tcad dato;
	int tam_cad;
};

typedef struct tlista{
	pnodo inicio;
	pnodo final;
};



void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_en_orden(tlista &lista, pnodo nuevo);
bool buscar_nodo(tlista lista, tcad valor);
void menu(int &op);
void ver_lista(pnodo inicio, pnodo final);
pnodo long_max(tlista lista);


main(){
	
	tlista li;
	pnodo nue,maxx;
	int op;
	iniciar_lista(li);

	
	do{
		system("cls");
		menu(op);
		
		
		switch(op){
		case 1:
			crear_nodo(nue);
			agregar_en_orden(li,nue);
			break;
			
		case 2: 
			
			maxx=long_max(li); 
			if(maxx!=NULL){
				cout<<"cadena mas larga es: "<<maxx->dato<<endl;
			}else{
				cout<<"lista vacia"<<endl;
			}
			break;
		case 3: ver_lista(li.inicio, li.final); break;
		
		case 4: cout<<"fin.."<<endl;break;
		
		
		default: cout<<"opc. invalida"<<endl;
		
		
		
		}
		
		system("pause");
	} while(op!=4);
	
}
	
	
	void menu(int &op){
		cout<<"1- Agregar en orden"<<endl;
		cout<<"2- Buscar longitud maxima"<<endl;
		cout<<"3- Ver lista"<<endl;
		cout<<"4- Salir"<<endl;	
		cin>>op;
	}
		
		
		
void iniciar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
}

void crear_nodo(pnodo &nuevo){
	nuevo=new tnodo;
	
	if(nuevo!=NULL){
		cout<<"ingrese cadena: ";
		fflush(stdin);
		gets(nuevo->dato);
		
		nuevo->sig=NULL;
		nuevo->tam_cad=strlen(nuevo->dato);
	}else{
		cout<<"memoria insuficiente"<<endl;
	}
}

	void agregar_en_orden(tlista &lista, pnodo nuevo){
		pnodo i;
		
		//lista vacia
		if(lista.inicio==NULL){
			lista.inicio=nuevo;
			lista.final=nuevo;
		}else{ 
			if(!buscar_nodo(lista, nuevo->dato)){
				//evaluo extremo menor
				if( strcmp( nuevo->dato , lista.inicio->dato) <0 ){
					nuevo->sig = lista.inicio;
					lista.inicio=nuevo;
				}else{
					//evaluo extremo mayor
					if( strcmp(nuevo->dato , lista.final->dato)>0 ){
						lista.final->sig=nuevo;
						lista.final=nuevo;
					}else{
						//evaluar posicion
						for(i=lista.inicio; i!=NULL &&  strcmp( (i->sig)->dato , nuevo->dato )<0   ; i=i->sig);
						
						nuevo->sig=i->sig;
						i->sig=nuevo;
						
					}
				}
				cout<<"nodo agregado"<<endl;
			}else{
				cout<<"nodo ya existe, liberando memoria"<<endl;
				delete(nuevo);
			}
			

		}
	}
		
		
		bool buscar_nodo(tlista lista, tcad valor)
		{ pnodo i;
		bool encontrado=false;
		if (lista.inicio!=NULL)
			for(i=lista.inicio;i!=NULL && encontrado==false;i=i->sig)
			if ( strcmp(i->dato,valor) == 0)
				encontrado=true;
		return encontrado;
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

    pnodo long_max(tlista lista){
		pnodo i,maximo;
		
		
		if(lista.inicio!=NULL){
			maximo=lista.inicio;
			
			for(i=lista.inicio; i!=NULL; i=i->sig){
				if(strlen(maximo->dato)<strlen(i->dato) ){
					maximo=i;
				}
			}
			
		}else{
			maximo=NULL;
		}
		return maximo;
	}
