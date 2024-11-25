///Utilizando el TDA pila y sus operaciones básicas codifique un algoritmo
///que permita determinar si un número es capicúa o no

#include <iostream>
using namespace std;

const int MAX=20;
//#include "TDA_Pila.hpp"
#include "TDA_PilaV2arreglos.hpp"
//#include "TDA_Pila_ListasDCont.hpp"

bool misterio(int num);


main()
{ int num;
    cout<<"Ingrese valor: ";
    cin>>num;
    if(misterio(num)==true)
        cout<<"capicua"<<endl;
    else
        cout<<"no capi"<<endl;
}

bool misterio(int num)
{ tpila p;
  int aux,i, inverso;
  iniciar_pila(p);
  aux=num;
  while(aux > 0)
  {  agregar_pila(p,aux % 10);
     aux=aux / 10; }
     i=1;
     inverso=0;
  while (pila_vacia(p)!=true)
   { inverso=inverso + quitar_pila(p)*i;
     i=i*10; }
    return num==inverso; }
