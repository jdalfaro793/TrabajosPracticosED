/*
a)Consigne la declaración de tipos y variables de la estructura.
Considere que, por cada carácter, se crea un único nodo que registra las veces
que intentó almacenarse un dato determinado.
b)Diseñe un procedimiento/función que permita agregar al final de la lista un nuevo.
Los nodos no agregados deben ser liberados.
c)Diseñe un procedimiento/función que permita quitar valor específico de la lista.
Téngase en cuenta que si el carácter se agregó 2 o más veces sólo debe actualizarse la cantidad de apariciones.

*/

#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
            char dato;
            int cant;
            pnodo sig;
};

typedef struct tlista{
            pnodo inicio;
            pnodo fin;
};

void iniciar_lista(tlista &lis);
void crear_nodo(pnodo &nuevo);
void agregar_final(tlista &lis, pnodo nuevo);
void quitar_especifico(tlista &lis, char dato);
void mostrar(tlista lis);

main()
{
    tlista lista;
    pnodo nuevo;
    int op;
    char dato;
    iniciar_lista(lista);
    do{
        cout<<"\n 1-agregar"<<endl;
        cout<<"2-quitar"<<endl;
        cout<<"3-mostrar"<<endl;
        cout<<"0-salir"<<endl;
        cout<<"ingrese op: ";
        cin>>op;
        switch(op)
        {
            case 1: crear_nodo(nuevo);
                    agregar_final(lista,nuevo);
                break;
            case 2:
                    cout<<"ingrese valor a eliminar: ";
                    cin>>dato;
                    quitar_especifico(lista,dato);
                    break;
            case 3: mostrar(lista);
        }
    }while(op!=0);

}

void iniciar_lista(tlista &lis)
{
    lis.inicio=NULL;
    lis.fin=NULL;
}
void crear_nodo(pnodo &nuevo)
{
    nuevo=new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese letra: ";
        cin>>nuevo->dato;
        nuevo->cant=1;
        nuevo->sig=NULL;
    }
}
void agregar_final(tlista &lis, pnodo nuevo)
{ pnodo p;
    if(lis.inicio==NULL)
    {
        lis.inicio=nuevo;
        lis.fin=nuevo;
    }
    else
    { p=lis.inicio;
      while(p!=NULL && p->dato!=nuevo->dato)
      {
          p=p->sig;
      }
      if(p==NULL) //no lo encontro
        {
            lis.fin->sig=nuevo;
            lis.fin=nuevo;
        }
      else
        {
            p->cant++;
            delete(nuevo);
        }
    }
}
void quitar_especifico(tlista &lis, char dato)
{
    pnodo i, extraido=NULL, previo=NULL;
    bool existe=false;

    i=lis.inicio;
    while(i!=NULL && existe==false)
    {
        if(i->dato==dato)
            existe=true;
        else
        {
            previo=i;
            i=i->sig;
        }
    }
    if(existe==true)
    {
        if(i->cant>1)
            {i->cant--;
            cout<<"extraido "<<i->dato<< " cant "<<i->cant<<endl;
            }
        else
        { extraido=i;
          if(extraido==lis.inicio)
            if(lis.inicio==lis.fin)
            {
               iniciar_lista(lis);
            }
            else
            {
                lis.inicio=extraido->sig;
                extraido->sig=NULL;
            }
         else
             {
                 previo->sig=extraido->sig;
                 extraido->sig=NULL;
                 if(extraido==lis.fin)
                    lis.fin=previo;
             }
        cout<<"extraido "<<extraido->dato<< " cant "<<extraido->cant<<endl;
        delete(extraido);
        }

    }
    else
        cout<<"el nodo no existe"<<endl;

}
void mostrar(tlista lis)
{
    pnodo i;
    for(i=lis.inicio; i!=NULL;i=i->sig)
        cout<<i->dato<<"  "<<i->cant<<"  /  ";
}
