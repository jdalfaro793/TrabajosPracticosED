#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int *p_entero;
main()
{ 
	p_entero p;
	p=new int; //Reservando espacio de memoria para un entero
	if (p==NULL) //Verificación del puntero
		cout << "\nNo pudo reservarse memoria" << endl;
	else
	{ 
		cout << "Direccion obtenida: " << p << endl;
		cout << "\nIngrese valor: ";
		cin >> *p; //Accediendo a la memoria reservada mediante p
		cout << "\nValor ingresado: " << *p << endl;
		delete(p); //Liberando memoria
		cout << "\nMemoria liberada " << endl;
	}

}
