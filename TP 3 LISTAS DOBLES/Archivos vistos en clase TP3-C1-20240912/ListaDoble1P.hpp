///*operaciones básicas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    char dato;
                    pnodo ant;
                    pnodo sig;
                    };


//Inicialización
void iniciar_lista(pnodo &lis)
{
    lis=NULL;
}

//Creación del nodo
void crear(pnodo &nuevo)
{
    nuevo=new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese valor: ";
        cin>> nuevo->dato;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria llena"<<endl;
}
void agregar_inicio(pnodo &lis, pnodo nuevo)
{
    if(lis==NULL)
        lis=nuevo;
    else{
        nuevo->sig=lis;
        lis->ant=nuevo;
        lis=nuevo;
    }
}

void agregar_final(pnodo &lis, pnodo nuevo)
{ pnodo i;
    if(lis==NULL)
        lis=nuevo;
    else
    {   for(i=lis;i->sig!=NULL;i=i->sig);
        i->sig=nuevo;
        nuevo->ant=i;
    }
}

pnodo quitar_inicio(pnodo &lis)
{
  pnodo extraido;
  if(lis==NULL)
    extraido=NULL;
  else
  { extraido=lis;
      if(lis->sig==NULL)
         lis=NULL;
      else
        {
            lis=lis->sig;
            lis->ant=NULL;
            extraido->sig=NULL;
        }
  }
    return extraido;
}
pnodo quitar_final(pnodo &lis)
{  pnodo extraido, i;
  if(lis==NULL)
    extraido=NULL;
  else
  {
    if(lis->sig==NULL)
        { extraido=lis;
          lis=NULL;
         }
    else
    {   for(i=lis;(i->sig)->sig!=NULL;i=i->sig);
        extraido=i->sig;
        i->sig=NULL;
        extraido->ant=NULL;
    }
  }
    return extraido;

}

int contar_nodos(pnodo lis)
{ int c;
  if(lis==NULL)
    c=0;
  else
    c=1+contar_nodos(lis->sig);
  return c;
}

void mostrar_lista(pnodo lis)
{
  if(lis!=NULL)
  {
    cout<<lis->dato<<"  ";
    mostrar_lista(lis->sig);
  }
  //else
    //cout<<"lista vacia"<<end;
}

void mostrar2(pnodo lis)
{
    pnodo ult,i;
    for(ult=lis;ult->sig!=NULL;ult=ult->sig);
    for(i=ult;i!=NULL; i=i->ant)
        cout<<i->dato<<"  ";

}

void cambio(char &a, char &b)
{
  char c;
  c=a;
  a=b;
  b=c;
}
void ordenar(pnodo lis)
{
  bool ordenado=false;
  pnodo i;
  while(ordenado==false)
  {
    ordenado=true;
    for(i=lis;i->sig!=NULL;i=i->sig) //(i=0;i<=ocup-1;i++)
      if(i->dato>(i->sig)->dato)
        {
          cambio(i->dato,(i->sig)->dato);
          ordenado=false;
        }
  }

}



void liberarLista(pnodo &lista) {
	pnodo p;
	while(lista!=NULL){
		p=lista->sig;
		delete(lista);
		lista=p;
	}
}
