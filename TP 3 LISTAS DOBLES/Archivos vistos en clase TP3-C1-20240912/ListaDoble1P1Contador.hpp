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


typedef struct tlista{
            pnodo inicio;
            int cont;
};

//Inicialización
void iniciar_lista(tlista &lis)
{
    lis.inicio=NULL;
    lis.cont=0;
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
void agregar_inicio(tlista &lis, pnodo nuevo)
{ pnodo i;
    if(lis.inicio==NULL)
        {lis.inicio=nuevo;
         nuevo->sig=lis.inicio;
         lis.inicio->ant=nuevo;
        }
    else{
        for(i=lis.inicio;i->sig!=lis.inicio;i=i->sig); //ultimo
        nuevo->sig=lis.inicio;
        lis.inicio->ant=nuevo;
        lis.inicio=nuevo;

        i->sig=lis.inicio;
        lis.inicio->ant=i;
    }
    lis.cont++;
}

void agregar_final(tlista &lis, pnodo nuevo)
{ pnodo i;
    if(lis.inicio==NULL)
        {lis.inicio=nuevo;
        nuevo->sig=lis.inicio;
         lis.inicio->ant=nuevo;
        }
    else
    {   for(i=lis.inicio;i->sig!=lis.inicio;i=i->sig);
        i->sig=nuevo;
        nuevo->ant=i;
        nuevo->sig=lis.inicio;
        lis.inicio->ant=nuevo;
    }
    lis.cont++;
}

pnodo quitar_inicio(tlista &lis)
{
  pnodo extraido, ult;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
  {  if(lis.cont==1)
        {extraido=lis.inicio;
          extraido->ant=NULL;
          extraido->sig=NULL;
        }
     else{ ult=lis.inicio->ant; //ultimmo
       extraido=lis.inicio;
       lis.inicio=lis.inicio->sig;
       extraido->sig=NULL;
       extraido->ant=NULL;
       lis.inicio->ant=ult;
       ult->sig=lis.inicio;
     }

   lis.cont--;
  }
    return extraido;
}
pnodo quitar_final(tlista &lis)
{  pnodo extraido, i, ult;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
  {
    if(lis.inicio->sig==NULL)
        { extraido=lis.inicio;
          lis.inicio=NULL;
         }
    else
    {   //for(i=lis.inicio;(i->sig)->sig!=NULL;i=i->sig);
        ult=lis.inicio->ant->ant; //ultimo

        extraido=ult->sig;
        ult->sig=lis.inicio;
        lis.inicio->ant=ult;
        extraido->ant=NULL;
        extraido->sig=NULL;
    }
    lis.cont--;
  }
    return extraido;

}

void mostrar_lista(tlista lis)
{ pnodo i;
   i=lis.inicio;
  if(lis.inicio!=NULL)
  do
  {
      cout<<i->dato<<"  ";
      i=i->sig;

  }while(i!=lis.inicio);
}
void mostrar2(tlista lis)
{ pnodo p;
  int i;
  if(lis.inicio!=NULL)
  { p=lis.inicio->ant;
    for(i=lis.cont;i>0;i--)
    {cout<<p->dato<<"  ";
      p=p->ant;
    }
  }
  //else
    //cout<<"lista vacia"<<end;
}

