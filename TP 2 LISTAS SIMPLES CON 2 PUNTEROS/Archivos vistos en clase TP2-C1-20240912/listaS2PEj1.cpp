
/*
Dada una lista simple de valores enteros, con punteros de inicio y final,
cómo se modificaría la implementación básica si se restringe la capacidad
de la lista a 20 nodos.
a Consigne la declaración de tipos y variables de la estructura.
b Diseñe un procedimiento/función que permita agregar un nuevo nodo a la lista
 considerando que los valores impares se añadirán por el inicio, mientras que
 los valores pares se agregarán por el final.
c Diseñe la operación lista_llena

*/

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
    int cont;
};

//Inicialización de la lista
void iniciar_lista(tlista &lis);

//Creación del nodo
void crear(pnodo &nuevo);
void agregar_inicio_final(tlista &lis, pnodo nuevo);
pnodo quitar_inicio(tlista &lis);
void mostrar_lista(tlista lis);

bool llena(tlista lis);
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
                        agregar_inicio_final(lista, nuevo);
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
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria llena"<<endl;
}

void agregar_inicio_final(tlista &lis, pnodo nuevo)
{
    if(llena(lis)==true)
        cout<<"no se puede agregar"<<endl;
    else{
       if(lis.inicio==NULL)
       {
           lis.inicio=nuevo;
           lis.fin=nuevo;
       }
       else{
            if(nuevo->dato%2==1) //impar
            {   nuevo->sig=lis.inicio;
                lis.inicio=nuevo;
            }
            else //pares
            {
                lis.fin->sig=nuevo;
                lis.fin=nuevo;
            }
       }
       lis.cont++;
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
    lis.cont--;
  }
    return extraido;
}


void mostrar_lista(tlista lis)
{  int j;
   pnodo i;
   //for(i=lis.inicio;i!=NULL;i=i->sig)
    //cout<<i->dato<<"  ";
    i=lis.inicio;
  for(j=1;j<=lis.cont;j++)
  {
      cout<<i->dato<<endl;
      i=i->sig;
  }
    cout<<"\ncantidad de nodos: "<<lis.cont<<endl;
}

bool llena(tlista lis)
{                           //return lis.cont==MAX
    if(lis.cont==MAX)
        return true;
    else
        return false;
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
