#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX=10;

#include "TDABiCola.hpp"

void menu(int &opc);

main()
{
    tbicola cola;
    int  nuevo, eliminado;
    int op, valor, extremo;
    iniciar_cola(cola);
    do{ system("cls");
        menu(op);
        switch(op)
        {
            case 1: cout<<".....Agregar valor ......"<<endl;
                    cin>>nuevo;
                      agregar_cola(cola, nuevo);
                    break;
            case 2: cout<<".....Quitar valor ......"<<endl;
                    //cout<<"Ingrese extremo a quitar 1.frente, 2.final: ";
                    //cin>>extremo;
                    if(cola_vacia(cola)!=true)
                      {	eliminado=quitar_cola(cola,2);
                        cout<<"Eliminado "<<eliminado<<endl;
                      }
                    else
                       cout<<" No se puede eliminar, cola vacia"<<endl;

                    break;

            case 3: if(cola_vacia(cola)!=true){
                    cout<<"Frente: "<< consultar_primero(cola)<<endl;
                    cout<<"Final: "<<consultar_ultimo(cola)<<endl;
                    }
                    else
                    cout<<"no hay elementos"<<endl;
					   break;
             case 4: cout<<"...........FIN DEL PROGRAMA..........."<<endl;
                    break;
            default : cout<<" OPCION INCORRECTA"<<endl;
        }
        system("pause");

    }while(op!=4);

}


void menu(int &opc)
{
    cout<<"..........MENU.........."<<endl;
    cout<<"1- Agregar un elemento"<<endl;
    cout<<"2- Quitar un elemento"<<endl;
    cout<<"3- Mostrar frente y final"<<endl;
    cout<<"4- Salir"<<endl;
    cout<<"Elija una opcion: ";
    cin>>opc;
}
