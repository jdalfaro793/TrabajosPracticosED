/*
operaciones básicas 2 punteros
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
                    pnodo ant;
                    pnodo sig;
                    };

typedef struct tlista{
        pnodo inicio;
        pnodo fin;
};


//Inicialización
void iniciar_lista(tlista &lis)
{
    lis.inicio=NULL;
    lis.fin=NULL;
}

//Creación del nodo
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
void agregar_inicio(tlista &lis, pnodo nuevo)
{
    if(lis.inicio==NULL)
    {
        lis.inicio=nuevo;
        lis.fin=nuevo;
    }
    else{
    nuevo->sig=lis.inicio;
    lis.inicio->ant=nuevo;
    lis.inicio=nuevo;
}
}

void agregar_final(tlista &lis, pnodo nuevo)
{
    if(lis.fin==NULL)
        {lis.inicio=nuevo;
        lis.fin=nuevo;
        }
    else
    {   nuevo->ant=lis.fin;
        lis.fin->sig=nuevo;
        lis.fin=nuevo;
    }
}

pnodo quitar_maximo(tlista &lis){ 
	pnodo extraido,mayor, i;

    if(lis.inicio==NULL) //vacio
        extraido=NULL;
    else
    {
        if(lis.inicio==lis.fin) //unico elemento
        {
            extraido=lis.inicio;
            lis.inicio=NULL;
            lis.fin=NULL;
        }
        else
        {
            mayor=lis.inicio;
            for(i=lis.inicio->sig;i!=NULL; i=i->sig)
                if(mayor->dato<i->dato)
                    mayor=i;
            if(mayor==lis.inicio)
            {
                extraido=mayor;
                lis.inicio=mayor->sig;
                lis.inicio->ant=NULL;
                extraido->sig=NULL;
            }
            else
                if(mayor==lis.fin)
                {
                extraido=mayor;
                lis.fin=mayor->ant;
                lis.fin->sig=NULL;
                extraido->ant=NULL;

                }
                else //en el medio
                {
                    extraido=mayor;
                    (mayor->ant)->sig=mayor->sig;
                    (mayor->sig)->ant=mayor->ant;
                    extraido->sig=NULL;
                    extraido->ant=NULL;
                }
        }
       
    }
		return extraido;
}




pnodo quitar_inicio(tlista &lis)
{
  pnodo extraido;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
    if(lis.inicio==lis.fin)
    {
        extraido=lis.inicio;
        lis.inicio=NULL;
        lis.fin=NULL;
    }
    else
      {
           extraido=lis.inicio;
           lis.inicio=lis.inicio->sig;
           lis.inicio->ant=NULL;
           extraido->sig=NULL;
      }
    return extraido;
}
pnodo quitar_final(tlista &lis)
{  pnodo extraido, i;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
  {
    if(lis.inicio->sig==NULL) //lis.inicio==lis.fin
        { extraido=lis.inicio;
           lis.fin=NULL;
          lis.inicio=NULL;
         }
    else
    {
        extraido=lis.fin;
        lis.fin=lis.fin->ant;
        lis.fin->sig=NULL;
        extraido->ant=NULL;
    }
  }
    return extraido;

}


void mostrar_lista(tlista lis)
{ pnodo i;
  if(lis.inicio!=NULL)
  {
    for(i=lis.inicio;i!=NULL;i=i->sig)
        cout<<i->dato<<"  ";
  }
  //else
    //cout<<"lista vacia"<<end;
}

void mostrar2(tlista lis)
{
    pnodo i;
    for(i=lis.fin;i!=NULL;i=i->ant)
        cout<<i->dato<<"  ";
}




void liberarLista(tlista &lista) {
	pnodo p;
	while(lista.inicio!=NULL){
		p=lista.inicio->sig;
		delete(lista.inicio);
		lista.inicio=p;
	}
}

void cambio (pnodo &a, pnodo &b){
    
	int dato;
	dato=a->dato;
	a->dato=b->dato;
	b->dato=dato;
}

void ordenar(tlista &lista){
	pnodo i,j;
	//cout<<"ejecutando"<<endl;
	
	for(i=lista.inicio; i!=lista.fin; i=i->sig){
		for(j=i->sig; j!=NULL; j=j->sig){
			if(i->dato > j->dato)
				cambio(i,j);
		}
	}
}
