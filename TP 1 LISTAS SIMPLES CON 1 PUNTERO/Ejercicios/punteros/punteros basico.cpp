#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int *p_entero;

main()
{ 
	int dato;
	
	p_entero p;
	
	cout << "Ingrese un dato:";
	cin >> dato;
	
	cout << "\nValor ingresado: " << dato << endl;
	
	p=&dato; //Guardando la direccion de la variable dato en el puntero p
	
	cout << "\nDireccion del dato: " << p << endl;
	cout << "\nValor apuntado por el puntero p: " << *p << endl; //Acceso al valor de la variable apuntada por p
	
}
