///*operaciones básicas
/*
El administrador de seguridad de una red informática desea mantener registrada información
acerca de los usuarios del sistema. Por cada usuario se debe guardar: id de usuario, apellido,
nombre, contraseña y cantidad de accesos. Considerando esto, se le solicita:
Consigne la declaración de tipos y variables de la estructura que represente la situación planteada.


*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char tcad[50];
typedef struct tusuario{
        int id;
        tcad nombre;
        tcad apellido;
        tcad pass;
        int accesos;
};

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    tusuario dato;//char dato;
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
void cargar_usuario(tusuario &usu);
void mostrar_usuario(tusuario usu);

void ordenar(tlista lis);

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
                      //cout<<"Eliminado "<<eliminado->dato<<endl;
                      mostrar_usuario(eliminado->dato);
                      delete(eliminado);
                    }
                    else
                       cout<<" No se puede eliminar, lista vacia"<<endl;

                    break;

            case 3: cout<<"..........Lista.........."<<endl;
                    mostrar_lista(lista);
                    break;
            case 4: cout<<"..........Ordenar.........."<<endl;
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

void cargar_usuario(tusuario &usu)
{
    cout<<"\n Ingrese ID: ";
    cin>>usu.id;
    cout<<"Ingrese nombre:";
    fflush(stdin);
    gets(usu.nombre);
    cout<<"Ingrese apellido: ";
    gets(usu.apellido);
    cout<<"Ingrese contraseña: ";
    gets(usu.pass);
    cout<<"Ingrese accesos: ";
    cin>>usu.accesos;
}
void mostrar_usuario(tusuario usu)
{
    cout<<"\nID: "<<usu.id<<endl;
    cout<<"nombre: "<<usu.nombre<<endl;
    cout<<"apellido: "<<usu.apellido<<endl;;
    cout<<"contraseña: "<<usu.pass<<endl;
    cout<<"accesos: "<<usu.accesos<<endl;
    cout<<endl;
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
        //cin>> nuevo->dato;
        cargar_usuario(nuevo->dato);
        nuevo->ant=NULL;
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria llena"<<endl;
}
void agregar_inicio(tlista &lis, pnodo nuevo)
{
    if(lis.inicio==NULL)
        lis.inicio=nuevo;
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
    //cout<<i->dato<<"  ";
     mostrar_usuario(i->dato);
  }
  //else
    //cout<<"lista vacia"<<end;
}

void cambio(tusuario &a, tusuario &b)
{
  tusuario c;
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
      if(i->dato.id>(i->sig)->dato.id)
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

