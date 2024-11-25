/*
Lista circular con un único puntero:
a.defina las estructuras de datos que permitan representarla e
b.implemente las operaciones iniciar_lista, agregar_final,
quitar_nodo (según un valor específico) y mostrar_lista.
c.contar nodos de manera recursiva
*/
///operaciones básicas LSC 1P


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    };


//Inicialización de la lista
void iniciar_lista(pnodo &lis);

//Creación del nodo
void crear(pnodo &nuevo);
void agregar_final(pnodo &lis, pnodo nuevo);
pnodo quitar_especifico(pnodo &lis, int valor);
void mostrar_lista(pnodo lis);
void mostrar(pnodo lis);
void menu(int &op);
int contar_nodos(pnodo lis, pnodo limite);


main()
{
    pnodo lista;
    pnodo nuevo, eliminado;
    int op, opc2;
    int dato;
    iniciar_lista(lista);

    do{ system("cls");
        menu(op);
        switch(op)
        {
            case 1: cout<<".....Agregar valor ......"<<endl;
                    crear(nuevo);
                    if(nuevo!=NULL)
                        agregar_final(lista, nuevo);
                    else
                        cout<<"Memoria llena"<<endl;
                    break;

            case 2: cout<<".....Quitar valor ......"<<endl;
                    cout<<"Ingrese valor a quitar: ";
                    cin>>dato;
                    eliminado=quitar_especifico(lista, dato);
                    if(eliminado!=NULL)
                    {
                      cout<<"Eliminado "<<eliminado->dato<<endl;
                      delete(eliminado);
                    }
                    else
                       cout<<" No se puede eliminar, lista vacia"<<endl;

                    break;

            case 3: cout<<"..........Lista.........."<<endl;
                    mostrar(lista);
                    cout<<"\n cantidad de nodos: "<<contar_nodos(lista,lista)<<endl;
                    break;
            case 0: cout<<"...........FIN DEL PROGRAMA..........."<<endl;

                    break;
            default : cout<<" OPCION INCORRECTA"<<endl;
        }
        system("pause");

    }while(op!=0);


}

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
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria llena"<<endl;
}

void agregar_final(pnodo &lis, pnodo nuevo)
{ pnodo i;
    if(lis==NULL)
        {lis=nuevo;
          nuevo->sig=lis; //lis->sig=lis;
        }
    else
    {   for(i=lis;i->sig!=lis;i=i->sig);
        i->sig=nuevo;
        nuevo->sig=lis; //(i->sig)->sig=lis
    }
}

void agregar_enOrden(pnodo &lis, pnodo nuevo)
{
    pnodo i;
    if(lis==NULL)
        {lis=nuevo;
         nuevo->sig=lis;
        }
    else
    {
        if(nuevo->dato<lis->dato)
        { for(i=lis;i->sig!=lis;i=i->sig);//i en el ultimo nodo
          nuevo->sig=lis;
          lis=nuevo;
          i->sig=lis;
        }
        else
        {
            for(i=lis;i->sig!=lis && (i->sig)->dato < nuevo->dato;i=i->sig);
            nuevo->sig=i->sig;
            i->sig=nuevo;
        }
    }
}

pnodo quitar_especifico(pnodo &lis, int valor)
{  pnodo extraido, i;
  if(lis==NULL)
    extraido=NULL;
  else
  {
    if(lis->dato==valor)
        if(lis->sig==lis)//unico nodo
        {
            extraido=lis;
            lis=NULL;
            extraido->sig=NULL;
        }
        else
        { for(i=lis;i->sig!=lis;i=i->sig);
          extraido=lis;
          lis=lis->sig;
          extraido->sig=NULL;
          i->sig=lis; //mantiene la lista circular
         }
    else
    {   for(i=lis;i->sig!=lis && valor!=(i->sig)->dato;i=i->sig);
        if(i->sig!=lis)
        {   extraido=i->sig;
            i->sig=extraido->sig;
            extraido->sig=NULL;
        }
        else
            extraido=NULL;
    }
  }
    return extraido;

}

int contar_nodos(pnodo lis, pnodo limite)
{ int c;
 if(lis==NULL)
    c=0;
 else{
  if(lis->sig==limite)
    c=1;
  else
    c=1+contar_nodos(lis->sig, limite);
 }
  return c;
}

void mostrar(pnodo lis)
{
    pnodo i;
    if(lis!=NULL){
    cout<<lis->dato<<"  ";
    for(i=lis->sig;i!=lis;i=i->sig)
        cout<<i->dato<<"  ";
    }

}


void menu(int &op)
{
    cout<<"****MENU****"<<endl;
    cout<<"1-agregar"<<endl;
    cout<<"2-eliminar"<<endl;
    cout<<"3-mostrar y contar"<<endl;
    cout<<"0-salir"<<endl;
    cout<<"elija opcion: ";
    cin>>op;
}

