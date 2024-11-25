///Utilizando el TDA pila y sus operaciones básicas codifique un algoritmo
///que permita calcular un término cualquiera de la secuencia de Fibonacci


#include <iostream>
using namespace std;

const int MAX=20;
#include "TDA_Pila.hpp"
//#include "TDA_PilaV2arreglos.hpp"
//#include "TDA_Pila_ListasDCont.hpp"

int fibo(int num);


main()
{ int num;
    cout<<"Ingrese valor: ";
    cin>>num;
    cout<<" el termino "<<num<<" de fibo es: "<<fibo(num)<<endl;
}

int fibo(int ter)
{
    tpila p;
    int valor,t,i ;
    iniciar_pila(p);
    if(ter==1 || ter==2)
        valor=1;
    else
    {
        agregar_pila(p,1);
        agregar_pila(p,1);
        for(i=3;i<ter;i++)
        {
            t=quitar_pila(p);
            valor=t+quitar_pila(p);
            agregar_pila(p,t);
            agregar_pila(p,valor);
        }
        valor=quitar_pila(p)+quitar_pila(p);
    }
    return valor;
}
