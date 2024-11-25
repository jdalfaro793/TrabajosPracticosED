#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAX = 6;

typedef int tcontenedor[MAX];

typedef struct tpila {
	tcontenedor datos1;
	tcontenedor datos2;
	tcontenedor datos3;	
};

void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, int valor);
int extraer_valor(tpila &pila);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);



void menu(char &op);

int main(int argc, char *argv[])
{
	
	char op;
	tpila pila;
	
	int nuevo, extraido;
	
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
	pila.datos1[MAX-1]=-1;
}



void agregar_valor(tpila &pila, int valor)
{
	int i;
	
	if(pila_llena(pila))
	{
		cout << "pila llena" << endl;
	}
	else
	{
		pila.datos1[MAX-1]++;
	

		if(pila.datos1[MAX-1] < MAX){ // VALIDANDO CIMA MENOR A 6 PARA GUARDAR EN DATOS1
			pila.datos1[pila.datos1[MAX-1]]=valor;
		}else{
			if(pila.datos1[MAX-1] < 2*MAX){ //VALIDANDO CIMA MENOR A 12 PARA GUARDAR EN DATOS2
				pila.datos2[pila.datos1[MAX-1] - MAX]=valor;
			}else{
				pila.datos3[ pila.datos1[MAX-1]- (2*MAX) ]=valor; // SI NO , GUARDAR EN DATOS3
			}
		}
		
		if(pila.datos1[MAX-1] == MAX-1)  //SI ES POS 5 SE INCREMENTA A 6
		   pila.datos1[MAX-1]++;
		

	}
}

int extraer_valor(tpila &pila)
{
	int res;
	if(pila_vacia(pila))
	{
		res=-99999;
	}
	else
	{
		
		
		if(pila.datos1[MAX-1] < MAX-1){
			
			res=pila.datos1[pila.datos1[MAX-1]];
		}else{
			if(pila.datos1[MAX-1]<2*MAX)
				res=pila.datos2[pila.datos1[MAX-1]-MAX];
			else
				res=pila.datos3[pila.datos1[MAX-1]-2*MAX];
		}
		
		pila.datos1[MAX-1]--;
		
		if(pila.datos1[MAX-1]== MAX-1)
			pila.datos1[MAX-1]--;

		
	}
	
	return res;
}

bool pila_vacia(tpila pila)
{
	bool res;
	
	res = pila.datos1[MAX-1]==-1;
	
	return res;
}


bool pila_llena(tpila pila)
{
	bool res;
	
	res = pila.datos1[MAX-1]==3*MAX-1;
	
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

