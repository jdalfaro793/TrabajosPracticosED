#include <iostream>
#include "OB2P_P2.hpp"

using namespace std;

main(){
	tlista li;
	pnodo nue,extraido;
	int op;
	
	iniciar_lista(li);
	
	do{
		system("cls");
		menu(op);
		
		switch(op){
		case 1: 
				crear_nodo(nue);
				if(nue!=NULL) {
					agregar_final(li,nue);
				}
				break;
		case 2:
			extraido=quitar_inicio(li);
			if(extraido!=NULL) cout<<"Nodo extraido: "<<extraido->dato<<endl;
			break;
		case 3:
			mostrar_lista(li);
			break;
			
		case 4: cout<<"FIN"<<endl; break;
		
		default: cout<<"opcion invalida.."<<endl;
		};
		system("pause");
	}while(op!=4);
}
