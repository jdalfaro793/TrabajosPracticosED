///*operaciones básicas


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//#include "ListaDoble1P.hpp" //debe cambiar la lista de tlista a pnodo
//#include "ListaDoble1P1Contador.hpp"
#include "ListaDoble2punteros.hpp"

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

