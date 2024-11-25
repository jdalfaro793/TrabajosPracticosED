/*
Dada una lista de caracteres, con un único puntero de inicio, realice
lo siguiente:
* lista de productos que almacene codigo, descripción, precio, cantidad

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

typedef char tcad[40];
typedef struct tprod{
        int codigo;
        tcad nombre;
        float precio;
        int stock;
};


typedef struct tnodo *pnodo;

typedef struct tnodo{

                    tprod dato;
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
void cargar(tprod &producto);
void mostrar(tprod producto);

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
                      cout<<"Eliminado "<<endl;
                      mostrar(eliminado->dato);
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
        cout<<"Ingrese valor: "<<endl;
        cargar(nuevo->dato);
        //cin>> nuevo->dato;
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
        for(i=lis;i!=NULL && i->dato.codigo!=nuevo->dato.codigo;i=i->sig);
        if(i==NULL){
            //agrega final
            for(i=lis;i->sig!=NULL;i=i->sig);
            i->sig=nuevo;
        }
        else
        {
          cout<<"el valor ya existe no se puede agregar"<<endl;
          cout<<"se actualiza el stock"<<endl;
          i->dato.stock=i->dato.stock+nuevo->dato.stock;
        }
    }
}


pnodo quitar_minimo(pnodo &lis) //minimo stock
{  pnodo extraido, i, minimo=NULL;
  char valor;
  if(lis==NULL)
    minimo=NULL;
  else
  {
    if(lis->sig==NULL)
        { minimo=lis;
          lis=NULL;
         }
    else
    {  //buscar el minimo stock
        minimo=lis;
        for(i=lis->sig; i!=NULL; i=i->sig)
            if(i->dato.stock < minimo->dato.stock)
                minimo=i;
        //quita un específico
        //FALTO considerar que el minimo esté en la primera posición donde
        //cambiaría el puntero lis
        if(minimo==lis)
        {  // extraido=minimo;
            lis=minimo->sig;
            minimo->sig=NULL;
        }
        else{
            for(i=lis;i->sig!=NULL && minimo!=i->sig;i=i->sig);
            if(i->sig!=NULL)
            {
                i->sig=minimo->sig;
                minimo->sig=NULL;
            }
            else
                minimo=NULL;
        }
    }
  }
    return minimo;

}

void mostrar_lista(pnodo lis)
{
  if(lis!=NULL)
  {
    //cout<<lis->dato<<"  ";
    mostrar(lis->dato);
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

void cambio(tprod &a, tprod &b)
{
    tprod aux;
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
            if(i->dato.codigo >(i->sig)->dato.codigo)
            {
                cambio(i->dato,(i->sig)->dato);
                ordenado=false;
            }
    }
}

void cargar(tprod &producto){
cout<<"\nIngrese codigo: ";
cin>>producto.codigo;
cout<<"Ingrese descripcion: ";
fflush(stdin);
gets(producto.nombre);
cout<<"Ingrese precio: ";
cin>>producto.precio;
cout<<"Ingrese cantidad:";
cin>>producto.stock;
}
void mostrar(tprod producto)
{
cout<<"\n codigo: "<<producto.codigo<<endl;
cout<<"descripcion: "<<producto.nombre<<endl;
cout<<"precio: "<<producto.precio<<endl;
cout<<"cantidad:"<<producto.stock<<endl;
}
