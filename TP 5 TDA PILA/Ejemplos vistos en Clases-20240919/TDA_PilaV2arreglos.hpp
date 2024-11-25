#include<iostream>
#include <stdlib.h>
using namespace std;

///definición de la estructura
///pila con 2 contenedores donde la primera posición del 2do contenedor trabaja
///como la cima
typedef int tcontenedor[MAX];
typedef struct tpila{
        tcontenedor datos1;
        tcontenedor datos2; //datos2[0] es la cima
};
///operaciones
void iniciar_pila(tpila &p)
{
    p.datos2[0]=-1;//p.cima=-1;
}
bool pila_llena(tpila p)
{
    return p.datos2[0]==2*MAX-1; //==9
}
bool pila_vacia(tpila p)
{
    return p.datos2[0]==-1;
}
void agregar_pila(tpila &p, int valor)
{
    if(pila_llena(p)==true)
        cout<<"pila llena"<<endl;
    else
    {
        p.datos2[0]=p.datos2[0]+1;
        if(p.datos2[0]==MAX) //es la posición 5 posición de la cima
            p.datos2[0]++; // pasa a pos 6
        if(p.datos2[0]<MAX)
            p.datos1[p.datos2[0]]=valor;
        else
            p.datos2[p.datos2[0]-MAX]=valor;
    }
}
int quitar_pila(tpila &p)
{ int ext;
    if(pila_vacia(p)==true)
        ext=-9999;
    else
    {
        if(p.datos2[0]>MAX)
            ext=p.datos2[p.datos2[0]-MAX];
        else
            ext=p.datos1[p.datos2[0]];
        p.datos2[0]--; //cima
        if(p.datos2[0]==MAX)
            p.datos2[0]--; //pasa a 4

    }
    return ext;
}
int consultar_pila(tpila p)
{  int ext;
    if(pila_vacia(p)==true)
        ext=-9999;
    else
    {
         if(p.datos2[0]>MAX)
            ext=p.datos2[p.datos2[0]-MAX];
        else
            ext=p.datos1[p.datos2[0]];
    }

    return ext;

}
