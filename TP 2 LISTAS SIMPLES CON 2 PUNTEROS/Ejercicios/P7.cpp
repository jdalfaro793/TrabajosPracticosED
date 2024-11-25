#include <iostream>
using namespace std;


typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo inicio;
	pnodo final;
};



void menu(int &op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_final(tlista &lista, pnodo nuevo);
void mostrar_lista(pnodo ini, pnodo fin);
void contar_caracteres(pnodo ini, pnodo fin, int &cant_mayus, int &cant_min, int &cant_sim, int &cant_digitos);
int contar_nodos(pnodo inicio, pnodo fin);

main() {
	
	tlista li;
	pnodo nue;
	int op;
	
	iniciar_lista(li);
	
	int cma,cmi,cdi,csim;
	
	do{
		system("cls");
		menu(op);
		
		
		switch(op){
		case 1:
			crear_nodo(nue);
			agregar_final(li,nue);
			break;
			
		case 2: 
			cout<<"Cantidad nodos: "<<contar_nodos(li.inicio,li.final)<<endl;
			break;
		case 3: 
			cma=0,cmi=0,cdi=0,csim=0;
			contar_caracteres(li.inicio,li.final,cma,cmi,csim,cdi);
			cout<<"Cantidad mayus: "<<cma<<" minus: "<<cmi<<" simbolos: "<<csim<<" digitos: "<<cdi<<endl;
			break;
		case 4: 
			mostrar_lista(li.inicio, li.final); 
			cout<<endl;
			break;
		
		case 5:
			cout<<"fin.."<<endl;
			break;
			
		default: 
			cout<<"opc. invalida"<<endl;
			
		}
		
		system("pause");
	} while(op!=5);
	
}


void menu(int &op){
	cout<<"1- Agregar final"<<endl;
	cout<<"2- Contar nodos recursivo"<<endl;
	cout<<"3- Contar tipos de caracteres recursivo"<<endl;
	cout<<"4- Ver lista recursivo"<<endl;
	cout<<"5- Salir"<<endl;	
	cin>>op;
}

void iniciar_lista(tlista &lista){
	lista.inicio=NULL;
	lista.final=NULL;
}
	
void crear_nodo(pnodo &nuevo){
	nuevo=new tnodo;
		
	if(nuevo!=NULL){
		cout<<"ingrese caracter: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else{
		cout<<"memoria insuficiente"<<endl;
	}
}

void agregar_final(tlista &lista, pnodo nuevo){
	if(lista.inicio==NULL){
		lista.inicio=nuevo;
		lista.final=nuevo;
	}else{
		lista.final->sig=nuevo;
		lista.final=nuevo;
	}
}


void mostrar_lista(pnodo ini,pnodo fin){
	if(ini==NULL){
		cout<<"lista vacia..."<<endl;
	}else{
		if(ini==fin){
			cout<<ini->dato<<" ";
		}else{
			cout<<ini->dato<<" ";
			
			mostrar_lista(ini->sig, fin);
		}
	}	
}


void contar_caracteres(pnodo ini, pnodo fin, int &cant_mayus, int &cant_min, int &cant_sim, int &cant_digitos){
	if(ini==NULL){
		cout<<"lista vacia"<<endl;
	}else{
		if(ini==fin){
			
			if(ini->dato>='A' && ini->dato<='Z'){
				cant_mayus=cant_mayus+1;
			}else if(ini->dato>='a' && ini->dato<='z'){
				cant_min=cant_min+1;
			}else if(ini->dato>='0' && ini->dato<='9'){
				cant_digitos=cant_digitos+1;
			}else cant_sim=cant_sim+1;
			
		}else{
			
			
			if(ini->dato>='A' && ini->dato<='Z'){
				cant_mayus=cant_mayus+1;
			}else if(ini->dato>='a' && ini->dato<='z'){
				cant_min=cant_min+1;
			}else if(ini->dato>='0' && ini->dato<='9'){
				cant_digitos=cant_digitos+1;
			}else cant_sim=cant_sim+1;
			
			contar_caracteres(ini->sig, fin, cant_mayus, cant_min, cant_sim, cant_digitos);
		}
	}
}



int contar_nodos(pnodo inicio, pnodo fin){
	if(inicio==NULL){
		return 0;
	}else{
		if(inicio==fin) 
			return 1;
		else 
			return 1+contar_nodos(inicio->sig,fin);
	}
}





