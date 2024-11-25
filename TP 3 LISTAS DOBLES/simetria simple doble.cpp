#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};




void iniciar_lista(pnodo &inicio);
void agregar_inicio(pnodo &inicio, int dato);
void calcular_simetria(pnodo inicio);


main(){
	pnodo inicio;
	int dato;
	char op;
	
	
	iniciar_lista(inicio);
	
	
	do{
		cout<<"cargar valor: ";
		cin>>dato;
		
		agregar_inicio(inicio, dato);
		
		cout<<"seguir ingresando? s/n: ";
		cin>>op;
	} while(op!='n');
	
	
	calcular_simetria(inicio);
	
	
}



void iniciar_lista(pnodo &inicio){
	inicio=NULL;
}

	
void agregar_inicio(pnodo &inicio, int dato){
	
	pnodo nuevo;
	
	nuevo=new tnodo;
	
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
		
		if(inicio==NULL){
			inicio=nuevo;
		}else{
			nuevo->sig=inicio;
			inicio->ant=nuevo;
			inicio=nuevo;
		}
		
	}else{
		cout<<"memoria llena..."<<endl;
	}
}
	
	
void calcular_simetria(pnodo inicio){
	pnodo i,j;
	bool res=false;


	if(inicio!=NULL){
		if(inicio->sig!=NULL){
			i=inicio;
			for(j=inicio;j->sig!=NULL;j=j->sig);
			
			do{
				res=(i->dato)==(j->dato);
				
				if(res){
					i=i->sig;
					j=j->ant;
				}
			} while(i!=j && res && i->ant!=j);
		}
		
	}
	
	if(res){
		cout<<"es simetrica"<<endl;
	}else{
		cout<<"no es simetrica"<<endl;
	}

}
	
	

