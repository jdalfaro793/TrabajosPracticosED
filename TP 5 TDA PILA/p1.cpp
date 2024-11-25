#include <iostream>
using namespace std;


const int MAX=5;
typedef int tcontenedor[MAX];

typedef struct tpila {
	tcontenedor datos;
	int cima;
};


void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, int valor);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);
void consultar_ultimo(tpila pila);
int extraer_valor(tpila &pila);

void menu(char &op);

int main(int argc, char *argv[]) {
	
	char op;
	tpila pila;
	int nuevo, extraido;
	
	
	iniciar_pila(pila);
	

	
	

	
	do{
		
		system("cls");
		menu(op);
		
		switch(op){
		case 'a': 
			cout<<"ingrese valor"<<endl;
			cin>>nuevo;
			agregar_valor(pila,nuevo);
			break;
		case 'b':
			if(pila_vacia(pila))
				cout<<"pila vacia"<<endl;
			else{
				extraido=extraer_valor(pila);
				cout<<"valor: "<<extraido<<endl;
			}
			break;
		case 'c': 
			consultar_ultimo(pila);
			break;
		case 'd':
			cout<<"fin"<<endl;
			break;
			
		

	}
		system("pause");
	} while(op!='d');

	
	
	
	return 0;
}




void iniciar_pila(tpila &pila){
	pila.cima=-1;	
}
	
	
void agregar_valor(tpila &pila, int valor){
	
	if(pila_llena(pila)){
		cout<<"pila llena"<<endl;
	}else{
		pila.cima++;
		pila.datos[pila.cima]=valor;
		cout<<"agregado"<<endl;
	}
	
}

int extraer_valor(tpila &pila){
	int extraido;
	if(pila_vacia(pila)){
		extraido=9999999;
	}else{
		extraido=pila.datos[pila.cima];
		pila.cima--;
	}
	
	return extraido;
	   
}

bool pila_vacia(tpila pila){
	bool res;

	res=pila.cima==-1;

	return res;
}
	
	
bool pila_llena(tpila pila){
	bool res;
	
	res= pila.cima==MAX-1;
	
	return res;
}

void consultar_ultimo(tpila pila){
if(pila_vacia(pila))
   cout<<"pila vacia"<<endl;
else
	cout<<"valor: "<<pila.datos[pila.cima]<<endl;
}


void menu(char &op){
	
	cout<<"a-Agregar valor"<<endl;
	cout<<"b-Quitar valor"<<endl;
	cout<<"c-Consultar valor"<<endl;	
	cout<<"d-Salir"<<endl;
	cout<<"ingrese opcion: ";
	cin>>op;
}
