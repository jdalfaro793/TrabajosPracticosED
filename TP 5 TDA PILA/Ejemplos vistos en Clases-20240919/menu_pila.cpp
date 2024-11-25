#include<iostream>
#include <stdlib.h>
using namespace std;

const int MAX=10;
//#include "TDA_Pila.hpp"
//#include "TDA_PilaV2arreglos.hpp"
#include "TDA_Pila_ListasDCont.hpp"

void menu(int &op);

main()
{
    tpila pila;
    int valor;
    int op;
    iniciar_pila(pila);
    do{  system("cls");
        menu(op);
        switch (op){
            case 1: cout<<"Ingrese valor a apilar: ";
                    cin>>valor;
                    agregar_pila(pila,valor);
                    break;
            case 2: if(pila_vacia(pila)!=true)
                        { valor=quitar_pila(pila);
                        cout<<"elemento: "<<valor<<endl;
                        }
                    else
                        cout<<"pila vacia"<<endl;
                    break;
            case 3: if(pila_vacia(pila)!=true)
                        { valor=consultar_pila(pila);
                        cout<<"elemento: "<<valor<<endl;
                        }
                    else
                        cout<<"pila vacia"<<endl;
                    break;
            case 4: cout<<"Fin del programa"<<endl;
                    break;
            default: cout<<"opcion incorrecta";

        };
        system("pause");

    }while(op!=4);

}
void menu(int &op)
{
    cout<<"****MENU****"<<endl;
    cout<<"1-apilar"<<endl;
    cout<<"2-desapilar"<<endl;
    cout<<"3-Consultar tope"<<endl;
    cout<<"4-salir"<<endl;
    cout<<"Elija opcion: ";
    cin>>op;
}
