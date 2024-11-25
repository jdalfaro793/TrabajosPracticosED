
/*
Considerando una lista de valores enteros, con un único puntero de inicio,
modifique la definición y sus operaciones básicas de listas de modo que sea
 posible registrar la cantidad de valores pares y la cantidad de valores
 impares almacenados en la estructura. Desarrolle las operaciones iniciar_lista,
 crear_nodo, agregar_inicio, quitar_final y mostrar_lista.
*/


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
            int cp;
            int ci;
};
//Inicialización de la lista
void iniciar_lista(tlista &lis);
void crear(pnodo &nuevo);//exclusivo del nodo
void agregar_inicio(tlista &lis, pnodo nuevo);
pnodo quitar_final(tlista &lis);
void mostrar_lista(tlista lis);
void menu(int &op);

main()
{
    tlista lista;

    pnodo nuevo, eliminado;
    int opc2;
     iniciar_lista(lista);
    do{ system("cls");
        menu(opc2);
        switch(opc2){

         case 1: cout<<"Inicio"<<endl;
                crear(nuevo);
                agregar_inicio(lista, nuevo);
                break;
         case 2: cout<<"Quitar final"<<endl;
                eliminado=quitar_final(lista);
                break;
        case 3: cout<<"mostrar"<<endl;
                mostrar_lista(lista);
                cout<<"\ncantidad de pares: "<<lista.cp<<endl;
                cout<<"cantidad de impares: "<<lista.ci<<endl;
                break;
        case 4: cout<<"Fin del programa"<<endl;
        }
        system("pause");
    }while(opc2!=4);
}
void menu(int &op)
{
    cout<<"\n****MENU****"<<endl;
    cout<<"1-Agregar Inicio"<<endl;
    cout<<"2-Quitar Final"<<endl;
    cout<<"3-mostrar"<<endl;
    cout<<"4.salir"<<endl;
    cout<<"elija opcion: ";
    cin>>op;
}

void iniciar_lista(tlista &lis)
{
    lis.inicio=NULL;
    lis.cp=0;
    lis.ci=0;
}
void crear(pnodo &nuevo)
{
    nuevo=new tnodo;
    if(nuevo==NULL)
        cout<<"memoria llena"<<endl;
    else
    {
        cout<<"Ingrese dato:";
        cin>>nuevo->dato;
        nuevo->sig=NULL;
    }
}
void agregar_inicio(tlista &lis, pnodo nuevo)
{
    nuevo->sig=lis.inicio;
    lis.inicio=nuevo;
    if(nuevo->dato%2==0)
        lis.cp++;
    else
        lis.ci++;
}

pnodo quitar_final(tlista &lis)
{ pnodo extraido,i;
    if(lis.inicio==NULL) //lis.cp==0 && lis.ci==0;
        extraido=NULL;
    else
    {
        if(lis.inicio->sig==NULL) //lis.cp+lis.ci==1
        {
            extraido=lis.inicio;
            lis.inicio=NULL;  //iniciar_lista(lis);
            lis.cp=0;
            lis.ci=0;
        }
        else
        {
            for(i=lis.inicio;(i->sig)->sig!=NULL;i=i->sig);
            extraido=i->sig;
            i->sig=NULL;

        if(extraido->dato%2==0)
            lis.cp--;
        else
            lis.ci--;
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
