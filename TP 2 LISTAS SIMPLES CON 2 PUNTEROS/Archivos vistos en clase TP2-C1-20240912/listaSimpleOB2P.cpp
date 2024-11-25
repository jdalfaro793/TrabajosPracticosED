///*operaciones básicas


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int MAX=20;
typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
                    pnodo sig;
                    };
typedef struct tlista
{
    pnodo inicio;
    pnodo fin;
//    int cont;
};

//Inicialización de la lista
void iniciar_lista(tlista &lis);

//Creación del nodo
void crear(pnodo &nuevo);
void agregar_inicio(tlista &lis, pnodo nuevo);
void agregar_final(tlista &lis, pnodo nuevo);
pnodo quitar_inicio(tlista &lis);
void mostrar_lista(tlista lis);
void menu(int &op);



main()
{
    tlista lista;
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
                    eliminado=quitar_inicio(lista);
                    if(eliminado!=NULL)
                    {
                      cout<<"Eliminado "<<eliminado->dato<<endl;
                      delete(eliminado);
                    }
                    else
                       cout<<" No se puede eliminar, lista vacia"<<endl;

                    break;

            case 3: cout<<"..........Lista.........."<<endl;
                    mostrar_lista(lista);

                    break;
            case 0: cout<<"...........FIN DEL PROGRAMA..........."<<endl;

                    break;
            default : cout<<" OPCION INCORRECTA"<<endl;
        }
        system("pause");

    }while(op!=0);


}

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
    lis.inicio=nuevo;
   }
}

void agregar_final(tlista &lis, pnodo nuevo)
{ pnodo i;
    if(lis.inicio==NULL)
        {lis.inicio=nuevo;
          lis.fin=nuevo;
        }
    else
    {   //for(i=lis;i->sig!=NULL;i=i->sig);
        lis.fin->sig=nuevo;
        lis.fin=nuevo;
    }
}

pnodo quitar_inicio(tlista &lis)
{
  pnodo extraido;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
  { if(lis.inicio==lis.fin) //unico
    {
        extraido=lis.inicio;
        lis.inicio=NULL;
        lis.fin=NULL;
    }
    else{
       extraido=lis.inicio;
       lis.inicio=lis.inicio->sig;
       extraido->sig=NULL;
  }
  }
    return extraido;
}


void mostrar_lista(tlista lis)
{
   pnodo i;
   for(i=lis.inicio;i!=NULL;i=i->sig)
    cout<<i->dato<<"  ";
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
