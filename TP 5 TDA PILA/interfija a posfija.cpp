#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

const int MAX=100;

typedef char tcad[MAX];


typedef struct tposfija{
	tcad datos;
	int ocupado;
};

typedef struct tpila{
	tcad tcontenedor;
	int cima;
};


void iniciar_pila(tpila &pila);
void agregar_pila(tpila &pila, char valor);
void quitar_pila(tpila &pila);
char tope_pila(tpila pila);
bool pila_vacia(tpila pila);
bool pila_llena(tpila pila);
void interfija_a_postfija(tcad interfija);
void agregar_elemento(tposfija &pos, char valor);
void iniciar_posfija(tposfija &pos);
int jerarquia(char valor);

int oculto (int n);

int main(int argc, char *argv[]) {
	
	tcad cadena;
	
	cout<<"ingrese cadena interfija: "<<endl;
	
	fflush(stdin);
	
	gets(cadena);
		
	interfija_a_postfija(cadena);

	
	return 0;
}




void iniciar_pila(tpila &pila){
	pila.cima=-1;
}
	
	
void agregar_pila(tpila &pila, char valor){
	if(pila_llena(pila)){
		cout<<"pila llena"<<endl;
	}else{
		pila.cima++;
		pila.tcontenedor[pila.cima]=valor;
	}
}
	
	
void quitar_pila(tpila &pila){

	if(pila_vacia(pila)){
		cout<<"pila vacia"<<endl;
	}else{
	 pila.cima--;
	 
	 

	}

}
char tope_pila(tpila pila){
	char va;
	if(pila_vacia(pila)){
		va='@';
	}else{
		va=pila.tcontenedor[pila.cima];
	}
	return va;
}

bool pila_vacia(tpila pila){
	bool resp;
	
	resp=pila.cima==-1;
	
	return resp;
}


bool pila_llena(tpila pila){
	bool resp;
	
	resp=pila.cima==MAX-1;
	
	return resp;
}

	
void interfija_a_postfija(tcad interfija){
	int i;
	tposfija posfija;
	tpila pila;
	
	iniciar_posfija(posfija);
	iniciar_pila(pila);
	
	for( i=0; i < strlen(interfija) ; i++ ){
		
		if( interfija[i]>='0' && interfija[i]<='9' ){
			agregar_elemento(posfija,interfija[i]);
			
		}else{
				if( interfija[i]=='^'||
				   interfija[i]=='*' || 
				   interfija[i] =='/' || 
				   interfija[i]=='+' || 
				   interfija[i]=='-')
					if( jerarquia(interfija[i]) > jerarquia(tope_pila(pila)) )
					{
						agregar_pila(pila,interfija[i]);
					}
					else
					{
						while(!pila_vacia(pila) && jerarquia(interfija[i]) <= jerarquia(tope_pila(pila))){
						agregar_elemento(posfija, tope_pila(pila));
						quitar_pila(pila);
						}
						agregar_pila(pila,interfija[i]);
						
					}
				
		}
	}
	
	while(!pila_vacia(pila)){
		agregar_elemento(posfija,tope_pila(pila));
		quitar_pila(pila);
	}
	
	agregar_elemento(posfija,'\0');
	cout<<posfija.datos<<endl;
	
}

int jerarquia(char valor){
	int v=0;
	
	if(valor=='^')
		v=3;
	if(valor=='*' || valor =='/')
		v=2;
	if(valor=='+' || valor=='-')
		v=1;
		
	return v;
}

void agregar_elemento(tposfija &pos, char valor){
	if(pos.ocupado<MAX-1){
		pos.ocupado++;
		pos.datos[pos.ocupado] = valor;
	}else{
		cout<<"posfija llena"<<endl;
	}
}
	
void iniciar_posfija(tposfija &pos){
	pos.ocupado=-1;
}
