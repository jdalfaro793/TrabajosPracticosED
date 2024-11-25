/*
Dada una lista de caracteres, con un único puntero de inicio, realice
lo siguiente:
* Consigne la declaración de tipos y variables de la estructura.
* Diseñe un procedimiento/función que permita agregar, por el final de la lista, un nuevo nodo siempre que éste contenga un valor distinto a los ya almacenados.
* Diseñe un procedimiento/función que permita quitar el nodo que contenga el mínimo valor de la lista.
* Diseñe un procedimiento/función recursivo que determine cuántos nodos componen la lista.
* Ordenar los elementos de la lista
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    char dato;
                    pnodo sig;
                    };


//Inicialización de la lista
void iniciar_lista(pnodo &lis);

//Creación del nodo
void crear(pnodo &nuevo);
void agregar_final(pnodo &lis, pnodo nuevo);
pnodo quitar_minimo(pnodo &lis);
void mostrar_lista(pnodo lis);
void menu(int &op);
int contar_nodos(pnodo lis);
void ordenar(pnodo lis);

main()
{
    pnodo lista;
    pnodo nuevo, eliminado;
    int op;
    iniciar_lista(lista);

    do{ system("cls");
        menu(op);
        switch(op)
        {
            case 1: cout<<".....Agregar valor ......"<<endl;
                    crear(nuevo);
                    cout<<"Final "<<endl;
                     agregar_final(lista, nuevo);
                     break;
            case 2: cout<<".....Quitar valor ......"<<endl;

                    eliminado=quitar_minimo(lista);
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
                    cout<<"\n cantidad de nodos: "<<contar_nodos(lista)<<endl;
                    break;
            case 4: cout<<"......ORDENANDO LISTA..........."<<endl;
                    ordenar(lista);
                    mostrar_lista(lista);
                    break;
            case 5: cout<<"...........FIN DEL PROGRAMA..........."<<endl;
                    break;
            default : cout<<" OPCION INCORRECTA"<<endl;
        }
        system("pause");

    }while(op!=5);


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
        lis=nuevo;
    else
    {   //buscar
        for(i=lis;i!=NULL && i->dato!=nuevo->dato;i=i->sig);
        if(i==NULL){
            //agrega final
            for(i=lis;i->sig!=NULL;i=i->sig);
            i->sig=nuevo;
        }
        else
        {
          cout<<"el valor ya existe no se puede agregar";
        }
    }
}


pnodo quitar_minimo(pnodo &lis)
{  pnodo extraido, i, minimo=NULL;
  char valor;
  if(lis==NULL)
    extraido=NULL;
  else
  {
    if(lis->sig==NULL)
        { extraido=lis;
          lis=NULL;
         }
    else
    {  //buscar el minimo
        minimo=lis;
        for(i=lis->sig; i!=NULL; i=i->sig)
            if(i->dato < minimo->dato)
                minimo=i;
        valor=minimo->dato;
        //quita un específico
        //FALTO considerar que el minimo esté en la primera posición donde
        //cambiaría el puntero lis
        if(valor==lis->dato)
        {   extraido=minimo;
            lis=minimo->sig;
            minimo->sig=NULL;
        }
        else{
            for(i=lis;i->sig!=NULL && valor!=(i->sig)->dato;i=i->sig);
            if(i->sig!=NULL)
            {   extraido=i->sig;
                i->sig=extraido->sig;
                extraido->sig=NULL;
            }
            else
                extraido=NULL;
        }
    }
  }
    return extraido;

}

void mostrar_lista(pnodo lis)
{
  if(lis!=NULL)
  {
    cout<<lis->dato<<"  ";
    mostrar_lista(lis->sig);
  }
}

void menu(int &op)
{
    cout<<"****MENU****"<<endl;
    cout<<"1-agregar"<<endl;
    cout<<"2-eliminar minimo"<<endl;
    cout<<"3-mostrar y contar"<<endl;
    cout<<"4-ordenar"<<endl;
    cout<<"5-salir"<<endl;
    cout<<"elija opcion: ";
    cin>>op;
}

int contar_nodos(pnodo lis)
{
    if(lis==NULL)
        return 0;
    else
        return 1+contar_nodos(lis->sig);
}

void cambio(char &a, char &b)
{
    char aux;
    aux=a;
    a=b;
    b=aux;
}


void ordenar(pnodo lis)
{
    bool ordenado=false;
    pnodo i;
    while(ordenado==false)
    {
        ordenado=true;
        for(i=lis;i->sig!=NULL;i=i->sig)
            if(i->dato >(i->sig)->dato)
            {
                cambio(i->dato,(i->sig)->dato);
                ordenado=false;
            }
    }
}
