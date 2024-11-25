#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

void iniciar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
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

void agregar_inicio(tlista &lista, pnodo nuevo){
	//lista vacia
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{ //lista con mas de un elemento
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
	}
}

void agregar_final(tlista &lista, pnodo nuevo){
	//lista vacia
	if(lista.inicio==NULL){
	 lista.inicio=nuevo;
	 lista.final=nuevo;
	}else{ //lista con mas de un elemento
	 lista.final->sig=nuevo;
	 lista.final=nuevo;
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
				for(i=lista.inicio; i->sig!=NULL && (i->sig)->dato < nuevo->dato; i=i->sig);
				
				nuevo->sig=i->sig;
				i->sig=nuevo;
				
			}
		}
	}
}
	
pnodo quitar_inicio(tlista &lista){
	pnodo extraido;
	
	if(lista.inicio==NULL){
		extraido=NULL;
	}else{
		if(lista.inicio==lista.final){
			extraido=lista.inicio;
			lista.inicio=NULL;
			lista.final=NULL;
		}else{
			extraido=lista.inicio;
			lista.inicio=lista.inicio->sig;
			extraido->sig=NULL;
		}
	}
	
	return extraido;
}
		
pnodo quitar_final(tlista &lista){
	pnodo i,extraido;
	
	if(lista.final==NULL){
		extraido=NULL;
	} else {
		if(lista.inicio==lista.final){
			extraido=lista.final;
			lista.inicio=NULL;
			lista.final=NULL;
		}else{
			for(i=lista.inicio;(i->sig)!=lista.final ;i=i->sig);
			
			extraido=lista.final;
			lista.final=i;
			lista.final->sig=NULL;
			
			
		}
	}
	
	return extraido;
}

pnodo quitar_nodo_especifico(tlista &lista, int buscado){
	pnodo i, encontrado;
	
	
	if(lista.inicio==NULL){
		encontrado=NULL;
	} else {
		
		//analizar el primer elemento
		if(lista.inicio ==lista.final){
			if(lista.inicio->dato==buscado){
				encontrado=lista.inicio;
				lista.inicio=NULL;
				lista.final=NULL;
			}else{
				encontrado=NULL;
			}	
		}else{
			//con mas de un elemento
			//analizar el primero
			
			if(lista.inicio->dato==buscado){
				encontrado=lista.inicio;
				lista.inicio=lista.inicio->sig;
				encontrado->sig=NULL;
			}else{
				
				//pregunta anticipada para el medio o final
				for(i=lista.inicio;i->sig!=NULL && (i->sig)->dato!=buscado;i=i->sig);
				
				
				
					encontrado=i->sig;

					i->sig=encontrado->sig;
					encontrado->sig=NULL;
					
					if(encontrado==lista.final){
						lista.final=i;
					}

				
				
			}
			
		}
	}
	
	return encontrado;
	
}
	
	pnodo quitar_especifico(tlista &lista, int valor)
	{
		pnodo extraido, i;
		
		if(lista.inicio == NULL)    //lista vacia
		{
			extraido = NULL;
		}
		else
		{
			if(lista.inicio->dato == valor)     //extraccion del unico nodo
			{
				if(lista.inicio == lista.final)
				{
					extraido = lista.inicio;
					lista.inicio = NULL;
					lista.final = NULL;
				}
				else
				{
					extraido = lista.inicio;    // extraccion del primer nodo
					lista.inicio = lista.inicio->sig;
					extraido->sig = NULL;
				}
			}
			else
			{
				for(i=lista.inicio; i->sig != NULL && valor != (i->sig)->dato ; i=i->sig);
				if(i->sig != NULL)
				{
					extraido= i->sig;       // extraccion del medio o final
					i->sig = extraido->sig;
					extraido->sig = NULL;
					if(extraido == lista.final)
						lista.final = i;
				}
				else
				   extraido = NULL;    // valor no encontrado
			}
		}
		return extraido;
	}
	
	
void mostrar_lista(pnodo inicio, pnodo final){
	if(inicio==NULL){
		cout <<"lista vacia"<<endl;
	}else{
		//un elemento
		if(inicio==final){
			cout<<inicio->dato<<" ,";
		}else{
			cout<<inicio->dato<<" ,";
			mostrar_lista(inicio->sig, final);
		}
	}

}

	bool buscar_nodo(tlista lista, int valor)
	{ pnodo i;
	bool encontrado=false;
	if (lista.inicio!=NULL)
		for(i=lista.inicio;i!=NULL && encontrado==false;i=i->sig)
		if (i->dato==valor)
			encontrado=true;
	return encontrado;
	}	
