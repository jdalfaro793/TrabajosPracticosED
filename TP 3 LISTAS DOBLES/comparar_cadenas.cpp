#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	char dato;
	pnodo sig;
	pnodo ant;
};

typedef struct tcad{
	pnodo inicio;
	pnodo final;
};



void iniciar_lista(tcad &cad);
void crear(pnodo &nuevo);
void agregar_final(tcad &lis, char dato);
int comparar_cadenas(tcad cad1, tcad cad2);
void mostrar_lista(tcad lis);


main(){

	tcad cad1, cad2;
	pnodo nuevo;
	
	iniciar_lista(cad1);
	iniciar_lista(cad2);
	
	char caracter;
	cout<<"ingrese cadena 1: ";
	do{
		
		caracter=getchar();
		agregar_final(cad1,caracter);
		
	} while(caracter!='\n');

	cout<<"ingrese cadena 2: ";
	do{
		
		caracter=getchar();
		agregar_final(cad2,caracter);
		
	} while(caracter!='\n');
	
	
	cout<<"cadena 1: "<<endl;
	mostrar_lista(cad1);


	
	cout<<"cadena 2: "<<endl;
	mostrar_lista(cad2);

	cout<<endl;
	
	int ress=comparar_cadenas(cad1,cad2);
	if(ress==0){
		cout<<"cadenas iguales"<<endl;
	}else{
		if(ress==1){
			cout<<"cadena 1 es mayor"<<endl;
		}else{
			cout<<"cadena 2 es mayor"<<endl;
		}
	}
}
	
	
	
void iniciar_lista(tcad &cad){
	cad.inicio=NULL;
	cad.final=NULL;
	
}
	
	
	void crear(pnodo &nuevo)
	{
		nuevo=new tnodo;
		if(nuevo!=NULL)
		{
			cout<<"Ingrese valor: ";
			cin>> nuevo->dato;
			nuevo->sig=NULL;
			nuevo->ant=NULL;
		}
		else
		   cout<<"Memoria llena"<<endl;
	}
	
	
	
	
	void agregar_final(tcad &lis, char dato)
	{
		pnodo nuevo;
		nuevo=new tnodo;
		
		if(nuevo!=NULL){
			
			nuevo->dato=dato;
			nuevo->sig=NULL;
			nuevo->ant=NULL;
			
			if(lis.final==NULL)
			{lis.inicio=nuevo;
			lis.final=nuevo;
			}
			else
			{   nuevo->ant=lis.final;
			lis.final->sig=nuevo;
			lis.final=nuevo;
			}
			
		}
		

	}
	
	
	
	void mostrar_lista(tcad lis)
	{
		pnodo i;
		if(lis.inicio!=NULL)
		{
			for(i=lis.inicio;i!=NULL;i=i->sig)
				cout<<i->dato;
		}
		cout<<endl;
	}
	
	
	
int comparar_cadenas(tcad cad1, tcad cad2){
	pnodo i,j;
	int res;
	
	
	if(cad1.inicio!=NULL && cad2.inicio!=NULL){
		i=cad1.inicio;
		j=cad2.inicio;
		res=0; //suponer que son iguales
		
		while(i!=NULL && j!=NULL && res==0){
			
			if(i->dato == j->dato){  // no cambia res sigue en 0
				i=i->sig;   //mantiene igualdad pasamos al prox.
				j=j->sig;
			}else{
				if(i->dato>j->dato)
					res=1; // primera mayor que la 2da
				else
					res=-1;  //2da mayor que la primera
			}
		}
	/*	if(res == 0){
			if(i != NULL)  // si la primera cadena es más larga
				res = 1;
			else if(j != NULL)  // si la segunda cadena es más larga
				res = -1;
		}
		*/
	}else{
		res=-9999; //arbitrario
	}
	
	return res;
}
