#include <iostream>
#include "OB2P.hpp"

using namespace std;


void misterio(pnodo lis, int &a, int &b);

main(){
	tlista li;
	char res;
	pnodo nue;
	int dato,a,b;
	iniciar_lista(li);
	
	do{
		
		crear_nodo(nue);
		//agregar_inicio(li, nue);
		agregar_final(li, nue);
		//agregar_en_orden(li,nue);

		
		
		
		cout<<"\ndesea seguir agregando? (s/n): ";
		cin>>res;
		

	} while(!(res=='n' || res=='N'));
	
	mostrar_lista(li.inicio, li.final);
	

	
	if(li.inicio!=NULL){
		
		do{
			
			//cout<<"ingrese nodo a quitar: "<<endl;
			//cin>>dato;
		//	nue=quitar_especifico(li, dato);
			nue=quitar_final(li);	
			if(nue!=NULL){
				
				//mostrar_lista(li.inicio,li.final);
				cout<<"se quito el nodo: "<<nue->dato<< endl;
				cout<<"desea extraer mas? (s/n)"<<endl;
				cin>>res;
			}else{
				
				cout<<"nodo no existe, desea extraer mas? (s/n)";
				cin>>res;
				
			}
		} while(!(res=='n' || res=='N'));
		
	}
	
	
	
	
	
}
	
	
	
	void misterio(pnodo lis, int &a, int &b)
	{ if (lis==NULL)
	{ a=0;
	b=0; }
	else
	{
		if( lis->dato%2==0)
			misterio(lis->sig,a,b);
		else
		{ misterio(lis->sig, a, b);
		b=lis->dato+b;
		a++;
		}
	}
	}

