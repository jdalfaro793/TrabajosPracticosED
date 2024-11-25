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

//Inicialización de la lista
void iniciar_lista(tlista &lis);

//Creación del nodo
void crear(pnodo &nuevo);
void agregar_inicio(tlista &lis, pnodo nuevo);
void agregar_final(tlista &lis, pnodo nuevo);
pnodo quitar_inicio(tlista &lis);
pnodo quitar_final(tlista &lis);
void mostrar_lista(tlista lis);
void menu(int &op);

void mostrar2(tlista lis);



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
                        agregar_inicio(lista, nuevo);
                        //agregar_final(lista,nuevo);
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
                    cout<<"\nmostrar desde la ultima posición a la primera"<<endl;
                    mostrar2(lista);
                    break;
            case 4: cout<<"...........FIN DEL PROGRAMA..........."<<endl;
                    break;
            default : cout<<" OPCION INCORRECTA"<<endl;
        }
        system("pause");

    }while(op!=4);


}

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
{
    if(lis.inicio==NULL)
        {lis.inicio=nuevo;
        }
    else{
        nuevo->sig=lis.inicio;
        lis.inicio->ant=nuevo;
        lis.inicio=nuevo;
    }
    lis.cont++;
}

void agregar_final(tlista &lis, pnodo nuevo)
{ pnodo i;
    if(lis.inicio==NULL)
        lis.inicio=nuevo;
    else
    {   for(i=lis.inicio;i->sig!=NULL;i=i->sig);
        i->sig=nuevo;
        nuevo->ant=i;
    }
    lis.cont++;
}

pnodo quitar_inicio(tlista &lis)
{
  pnodo extraido;
  if(lis.inicio==NULL)
    extraido=NULL;
  else
  {  if(lis.cont==1)
        {extraido=lis.inicio;
        lis.inicio=NULL;
        }
     else{
       extraido=lis.inicio;
       lis.inicio=lis.inicio->sig;
       lis.inicio->ant=NULL;
       extraido->sig=NULL;
     }
   lis.cont--;
  }
    return extraido;
}
pnodo quitar_final(tlista &lis)
{  pnodo extraido, i;
  if(lis.inicio==NULL)
    extraido=NULL;
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
  }
    return extraido;

}

void mostrar_lista(tlista lis)
{ pnodo i;
  if(lis.inicio!=NULL)
  {for(i=lis.inicio;i!=NULL;i=i->sig)
    cout<<i->dato<<"  ";
  }
  //else
    //cout<<"lista vacia"<<end;
}
void mostrar2(tlista lis)
{ pnodo p;
  int i;
  if(lis.inicio!=NULL)
  { for(p=lis.inicio;p->sig!=NULL;p=p->sig); //p toma la dirección del último nodo
    for(i=lis.cont;i>0;i--)
    {cout<<p->dato<<"  ";
      p=p->ant;
    }
  }
  //else
    //cout<<"lista vacia"<<end;
}

void cambio(char &a, char &b)
{
  char c;
  c=a;
  a=b;
  b=c;
}
void ordenar(tlista lis)
{
  bool ordenado=false;
  pnodo i;
  while(ordenado==false)
  {
    ordenado=true;
    for(i=lis.inicio;i->sig!=NULL;i=i->sig) //(i=0;i<=ocup-1;i++)
      if(i->dato>(i->sig)->dato)
        {
          cambio(i->dato,(i->sig)->dato);
          ordenado=false;
        }
  }

}

void menu(int &op)
{
    cout<<"****MENU****"<<endl;
    cout<<"1-agregar"<<endl;
    cout<<"2-eliminar minimo"<<endl;
    cout<<"3-mostrar y contar"<<endl;
    cout<<"4-ordenar"<<endl;
    cout<<"4-salir"<<endl;
    cout<<"elija opcion: ";
    cin>>op;
}

