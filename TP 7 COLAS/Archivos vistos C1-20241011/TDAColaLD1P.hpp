///*operaciones básicas


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//const int MAX=10;
typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
                    pnodo ant;
                    pnodo sig;
                    };


typedef struct tcola{ ///tlista
            pnodo inicio;
            int cont;
};

void iniciar_cola(tcola &lis)
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
bool cola_llena(tcola lis)
{
    return lis.cont==MAX;
}
bool cola_vacia(tcola lis)
{
    return lis.cont==0; ///lis.inicio==NULL;
}
void agregar_cola(tcola &lis, int dato)
{ pnodo nuevo;
   if(cola_llena(lis)==true)
        cout<<"lista llena"<<endl;
   else
    {  crear(nuevo, dato);
        if(lis.inicio==NULL)
            {lis.inicio=nuevo; //final de cola
            }
        else{
            nuevo->sig=lis.inicio;
            lis.inicio->ant=nuevo;
            lis.inicio=nuevo;
        }
        lis.cont++;
   }
}

int quitar_cola(tcola &lis)
{  pnodo extraido, i;
  int ext;
  if(lis.inicio==NULL)
    ext=-999;
  else
  {
    if(lis.inicio->sig==NULL)
        { extraido=lis.inicio;
          lis.inicio=NULL;
          ext=extraido->dato;
         }
    else
    {   for(i=lis.inicio;(i->sig)->sig!=NULL;i=i->sig);
        extraido=i->sig;
        i->sig=NULL;
        extraido->ant=NULL;
        ext=extraido->dato;
    }
    lis.cont--;
    delete (extraido);
  }
    return ext;

}

int consultar_primero(tcola lis)
{
    int consultado;
    pnodo i;
    if(cola_vacia(lis))
        consultado=-999;
    else
    { for(i=lis.inicio;i->sig!=NULL;i=i->sig);
      consultado=i->dato;
    }
    return consultado;
}

int consultar_ultimo(tcola lis)
{
    int consultado;
    pnodo i;
    if(cola_vacia(lis))
        consultado=-999;
    else
    {
      consultado=lis.inicio->dato;
    }
    return consultado;
}
