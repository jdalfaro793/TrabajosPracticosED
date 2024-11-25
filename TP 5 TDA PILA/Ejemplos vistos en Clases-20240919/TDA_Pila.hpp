#include<iostream>
#include <stdlib.h>
using namespace std;

///definición de la estructura un contenedor y la cima

typedef int tcontenedor[MAX];
typedef struct tpila{
        tcontenedor datos;
        int cima;
};
///operaciones
void iniciar_pila(tpila &p)
{
    p.cima=-1;
}
bool pila_llena(tpila p)
{
    return p.cima==MAX-1;
}
bool pila_vacia(tpila p)
{
    return p.cima==-1;
}
void agregar_pila(tpila &p, int valor)
{
    if(pila_llena(p)==true)
        cout<<"pila llena"<<endl;
    else
    {
        p.cima++;
        p.datos[p.cima]=valor;
    }
}
int quitar_pila(tpila &p)
{ int ext;
    if(pila_vacia(p)==true)
        ext=-9999;
    else
    {
        ext=p.datos[p.cima];
        p.cima--;
    }
    return ext;
}
int consultar_pila(tpila p)
{  int ext;
    if(pila_vacia(p)==true)
        ext=-9999;
    else
    {
        ext=p.datos[p.cima];
    }
    return ext;

}
