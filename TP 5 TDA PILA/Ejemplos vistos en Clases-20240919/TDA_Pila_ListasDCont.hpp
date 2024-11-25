


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

///definición de la estructura
///pila listas dobles con un único puntero y un contador

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
                    pnodo ant;
                    pnodo sig;
                    };


typedef struct tpila{
            pnodo inicio;
            int cont;
};

//Inicialización
void iniciar_pila(tpila &lis)
{
    lis.inicio=NULL;
    lis.cont=0;
}

//Creación del nodo
void crear(pnodo &nuevo, int valor)
{
    nuevo=new tnodo;
    if(nuevo!=NULL)
    {
        nuevo->dato=valor;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria llena"<<endl;
}
bool pila_llena(tpila lis)
{
    return lis.cont==MAX;
}

bool pila_vacia(tpila lis)
{
    return lis.cont==0; //lis.inicio==NULL;
}

void agregar_pila(tpila &lis, int valor)
{ pnodo i, nuevo;
    crear(nuevo,valor);
    if(pila_llena(lis))
        cout<<"pila llena"<<endl;
    else{
        if(lis.inicio==NULL)
            lis.inicio=nuevo;
        else
        {   for(i=lis.inicio;i->sig!=NULL;i=i->sig);
            i->sig=nuevo;
            nuevo->ant=i;
        }
        lis.cont++;
    }
}

int quitar_pila(tpila &lis)
{  pnodo extraido, i;
    int ext;
  if (pila_vacia(lis) )//(lis.inicio==NULL)
    ext=-999;
  else
  {
    if(lis.inicio->sig==NULL)
        { extraido=lis.inicio;
          lis.inicio=NULL;
         }
    else
    {   for(i=lis.inicio;(i->sig)->sig!=NULL;i=i->sig);
        extraido=i->sig;
        i->sig=NULL;
        extraido->ant=NULL;
    }
    lis.cont--;
    ext=extraido->dato;
    delete(extraido);
  }
    return ext;

}

int consultar_pila(tpila p)
{
    int consultado;
    pnodo i;
    if(pila_vacia(p)==true)
        consultado=-999;
    else
    {
        for(i=p.inicio;i->sig!=NULL;i=i->sig);
        consultado=i->dato;
    }
    return consultado;
}
