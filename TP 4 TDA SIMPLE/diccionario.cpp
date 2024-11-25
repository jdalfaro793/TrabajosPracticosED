#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cctype>


using namespace std;

const int MAX_FRASE=15;



typedef char tcad[MAX_FRASE];


typedef struct palabra{
	tcad pa; //palabra 
	tcad ti; //tipo
	tcad def; //definicion
};


typedef struct tpalabra *ppalabra;  //puntero a la tpalabra
typedef struct tpalabra {
					palabra frase;
					ppalabra sig;
					};


typedef struct tdiccionario *pdiccionario; //puntero al tdiccionario
typedef struct tdiccionario {
					char clave;
					ppalabra valores;	
					pdiccionario sig;
					};




void vaciar_diccionario(pdiccionario &dicc);
void vaciar_banco_palabras(ppalabra &pal);


void generar_palabra(ppalabra &pal);
void generar_diccionario(pdiccionario &dicc, ppalabra pal);
void agregar_palabra_a_diccionario(pdiccionario &dicc, ppalabra pal);
void mostrar_diccionario(pdiccionario dicc);
ppalabra buscar_palabra(ppalabra valores, tcad pa);

pdiccionario buscar_clave(pdiccionario dicc, char clave);


int main(int argc, char *argv[]) {
	
	char resp;
	pdiccionario diccionario;
	ppalabra palabrita;
	
	
	vaciar_diccionario(diccionario);
	vaciar_banco_palabras(palabrita);

	
	do{
		generar_palabra(palabrita);
		agregar_palabra_a_diccionario(diccionario, palabrita);
		
		cout<<"Desea agregar otra palabra al diccionario? s/n ";
		cin>>resp;
	} while(resp!='n');


	mostrar_diccionario(diccionario);

	return 0;
}

void vaciar_diccionario(pdiccionario &diccionario){
	diccionario=NULL;
}

void vaciar_banco_palabras(ppalabra &p){
	p=NULL;
}

	
	
void generar_palabra(ppalabra &pal){
	
	palabra pp;
	tcad p,t,d;
	
	pal = new tpalabra;
	
	if (pal!=NULL){
		
		cout<<"Ingrese Palabra: "<<endl;
		fflush(stdin);
		gets(pp.pa);
		
		cout<<"Ingrese Tipo: "<<endl;
		fflush(stdin);
		gets(pp.ti);
		
		cout<<"Ingrese Definicion: "<<endl;
		fflush(stdin);
		gets(pp.def);
		
		pal->frase=pp;
		pal->sig=NULL;		
	}else{
		cout<<"memoria insuficiente......."<<endl;
	}
}

	
void generar_diccionario(pdiccionario &dicc, ppalabra pal){
	dicc= new tdiccionario;
	if(dicc!=NULL){
		dicc-> clave = toupper(pal->frase.pa[0]);
		dicc-> valores = pal;
		dicc-> sig=NULL;
	}else{
		cout<<"memoria insuficiente..."<<endl;
	}
}



void agregar_palabra_a_diccionario(pdiccionario &dicc, ppalabra pal){
	pdiccionario indice_dicc, i;
	ppalabra p;
	
	indice_dicc = buscar_clave(dicc, toupper(pal->frase.pa[0]));

	if(indice_dicc==NULL){
		
		if(dicc==NULL){
			
			generar_diccionario(dicc,pal);
			
		}else{
			
			generar_diccionario(indice_dicc,pal);
			
			
			if(indice_dicc->clave < dicc->clave){
				indice_dicc->sig=dicc;
				dicc=indice_dicc;
			}else{
				
				for(i=dicc;i->sig!=NULL && indice_dicc->clave > i->sig->clave; i=i->sig);
				
				indice_dicc->sig=i->sig;
				
				i->sig=indice_dicc;
				
			}
		}
		
	}else{
		
		if (buscar_palabra(indice_dicc->valores, pal->frase.pa) != NULL) {
			cout << "ya está registrada la palabra..." << endl;
			delete(pal);
		} else {
			if (strcmp(pal->frase.pa, indice_dicc->valores->frase.pa) < 0) {
				
				pal->sig = indice_dicc->valores;
				indice_dicc->valores = pal;
			} else {
				for (p = indice_dicc->valores; p->sig != NULL && strcmp(pal->frase.pa, p->sig->frase.pa) > 0; p = p->sig);
				pal->sig = p->sig;
				p->sig = pal;
			}
		}
		
		
	}
}
	

pdiccionario buscar_clave(pdiccionario dicc, char clave){
	pdiccionario encontrado,i;
	
	if(dicc==NULL)
		encontrado=NULL;
	else{
		for(i=dicc; i!=NULL && i->clave!=clave; i=i->sig); 
		
		encontrado=i;
	}
	
	return encontrado;
}
	
ppalabra buscar_palabra(ppalabra valores, tcad pa){
	ppalabra encontrado, i ;
	
	if(valores==NULL)
		encontrado=NULL;
	else{
		for(i=valores; i!=NULL &&  strcmp(i->frase.pa,pa)!=0 ;i=i->sig); 
		encontrado=i;
	}
	
	return encontrado;
}
	
	
	void mostrar_diccionario(pdiccionario dicc){
		system("cls");
		
		pdiccionario i;
		ppalabra p;
		
		for(i=dicc; i!=NULL; i=i->sig){
			cout<<"-------------"<<endl;
			cout<<"Clave: "<<i->clave<<endl;
			
			for(p = i->valores ; p!=NULL; p=p->sig){
				cout<<p->frase.pa<<" - ";				
			}
			cout<<endl;
			cout<<"-------------"<<endl;
		}
	}
