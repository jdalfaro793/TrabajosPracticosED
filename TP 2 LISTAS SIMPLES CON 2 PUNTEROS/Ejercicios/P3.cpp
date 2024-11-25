#include <iostream>
#include "OB2P_P3.hpp"
using namespace std;



main() {

	tlista li;
	pnodo nuevo;
	int op,tipo_op;
	float extraer;
	iniciar_lista(li);
	do{
		system("cls");
		menu(op);
		
		
		switch(op)
		{
		case 1:
			cout << ".....Agregar......" << endl;
			crear_nodo(nuevo);
			cout<<"ingrese:1. agregar inicio - 2. agregar final"<<endl;
			cin>>tipo_op;
			agregar_nodo_opcion(li,nuevo, tipo_op);
			
			break;
		case 2:
			cout << ".....Quitar ......" << endl;
			cout<<"ingrese:1. quitar inicio - 2. quitar final"<<endl;
			cin>>tipo_op;
			quitar_nodo_opcion(li, tipo_op);
			break;
		case 3:
			cout << ".....Mostrar......" << endl;
			mostrar_lista(li);
			cout<<endl;
			break;
		case 4:
			cout<<"FIN"<<endl;
			break;
		
		default: cout << " OPCION INCORRECTA" << endl;
		}
		
		system("pause");
	} while(op!=4);
	
}

