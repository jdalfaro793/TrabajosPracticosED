#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX = 5;

typedef char tcontenedor[MAX];

typedef struct tpila {
	tcontenedor datos1;
	tcontenedor datos2;
	int cima1;
	int cima2;
};


void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, char valor);
int extraer_valor(tpila &pila);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);
char tope_pila(tpila p);


void menu(char &op);

int main(int argc, char *argv[])
{
	
	char op;
	tpila pila;
	
	char nuevo, extraido;
	
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
			
			if(extraido!='@')
				cout<<"extraido: "<<extraido<<endl;
			else 
				cout<<"pila vacia"<<endl;
			break;
		case 't': 
			cout<<"tope es: "<<tope_pila(pila)<<endl;
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
	pila.cima1=-1;
	pila.cima2=-1;
	
}



void agregar_valor(tpila &pila, char valor)
{
	int i;
	
	if(pila_llena(pila))
	{
		cout << "pila llena" << endl;
	}
	else
	{
		if(pila.cima1<MAX-1) {
			pila.cima1++;
			pila.datos1[pila.cima1]=valor;
		}else{
			pila.cima2++;
			pila.datos2[pila.cima2]=valor;
		}
		
	}
}

int extraer_valor(tpila &pila)
{
	char res;
	if(pila_vacia(pila))
	{
		res='@';
	}
	else
	{
		if(pila.cima2>=0){
			res=pila.datos2[pila.cima2];
				pila.cima2--;
		}else{
			res=pila.datos1[pila.cima1];
			pila.cima1--;
				
		}
	}
	
	return res;
}

bool pila_vacia(tpila pila)
{
	bool res;
	
	res = pila.cima1==-1;
		
	return res;
}


bool pila_llena(tpila pila)
{
	bool res;
	
	res = pila.cima2==MAX-1;
	
	return res;
}



void menu(char &op)
{
	
	cout << "a-Agregar valor" << endl;
	cout << "b-Quitar valor" << endl;
	cout << "t-Tope pila" << endl;
	cout << "c-Salir" << endl;
	cout << "ingrese opcion: ";
	cin >> op;
}


char tope_pila(tpila p)
{ char aux='@';
if (pila_vacia(p)!=true)
{ if (p.cima2>=0)
	aux=p.datos2[p.cima2];
else
	aux=p.datos1[p.cima1];
}
return aux;
} 
