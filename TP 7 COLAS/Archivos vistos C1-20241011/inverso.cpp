#include <iostream>
using namespace std;

const int MAX=20;

//#include "TDACola.hpp"
#include "TDAColaAlm.hpp"

int inverso(int num);
main()
{
    int num, inv;

    do{
        cout<<"Ingrese numero: ";
        cin>>num;
    }while(num<=0);
    inv=inverso(num);
    cout<<"valor original: "<<num<<" inverso: "<<inv<<endl;
}

int inverso(int num)
{
    tcola q;
    iniciar_cola(q);
    while(num>0)
    {
        agregar_cola(q,num%10);
        num=num/10;
    }
    while(cola_vacia(q)!=true)
    {
        num=num*10+quitar_cola(q);
    }
    return num;
}
