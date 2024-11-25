#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX = 5;

typedef float tcontenedor[MAX];

typedef struct tpila {
	tcontenedor datos1;
	tcontenedor datos2;
	int cima;
	
};

void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, float valor);
float extraer_valor(tpila &pila);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);



void menu(char &op);

int main(int argc, char *argv[])
{
	
	char op;
	tpila pila;
	
	float nuevo, extraido;
	
	iniciar_pila(pila);
	
	do
	{
		system("cls");
		menu(op);
		switch(op)
		{
		case 'a':
			cout << "ingrese valor: ";
			cin >> nuevo;
			agregar_valor(pila, nuevo);
			break;
		case 'b':
			extraido=extraer_valor(pila);
			
			if(extraido!=-99999)
				cout<<"extraido: "<<extraido<<endl;
			else 
				cout<<"pila vacia"<<endl;
			break;
		case 'c':
			cout << "fin" << endl;
			break;
		}
		system("pause");
	}
	while(op != 'c');
	
	return 0;
}




void iniciar_pila(tpila &pila)
{
	pila.cima=-1;
}


void agregar_valor(tpila &pila, float valor)
{
	int i;
	
	if(pila_llena(pila))
	{
		cout << "pila llena" << endl;
	}
	else
	{
		pila.cima++;
		if(pila.cima<MAX){
			pila.datos1[pila.cima]=valor;
		}else{
			pila.datos2[pila.cima-MAX]=valor;
		}
	}
}

float extraer_valor(tpila &pila)
{
	float res;
	if(pila_vacia(pila))
	{
		res=-99999;
	}
	else
	{
		if(pila.cima<MAX){
			res=pila.datos1[pila.cima];
		}else{
			res=pila.datos2[pila.cima-MAX];
		}
		pila.cima--;
		
	}
	
	return res;
}

bool pila_vacia(tpila pila)
{
	bool res;
	
	res = pila.cima == -1;
	
	return res;
}


bool pila_llena(tpila pila)
{
	bool res;
	
	res = pila.cima == 2 * MAX -1 ;
	
	return res;
}



void menu(char &op)
{
	
	cout << "a-Agregar valor" << endl;
	cout << "b-Quitar valor" << endl;
	cout << "c-Salir" << endl;
	cout << "ingrese opcion: ";
	cin >> op;
}

