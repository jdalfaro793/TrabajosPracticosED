#include <iostream>
using namespace std;


const int MAX = 5;
typedef int tcontenedor[MAX];

typedef struct tpila
{
	tcontenedor datos;
	int cima;
};


void iniciar_pila(tpila &pila);
void agregar_valor(tpila &pila, int valor);
bool pila_llena(tpila pila);
bool pila_vacia(tpila pila);

int extraer_valor(tpila &pila);
int tope_pila(tpila pila);


void termino_serie(int valor);
void menu(char &op);


bool inverso(int n1, int n2);

int main(int argc, char *argv[])
{
	
	int nuevo, n1, n2;
	
	cout << "ingrese termino: " ;
	cin >> nuevo;
	
	termino_serie(nuevo);
	
	
	
	cout<<"ingrese n1: ";
	cin>>n1;
	cout<<"ingrese n2: ";
	cin>>n2;
	
	if(inverso(n1, n2)){
		cout<<"son inversos"<<endl;
	}else{
		cout<<"no son inversos"<<endl;
	}
	
	return 0;
}




void iniciar_pila(tpila &pila)
{
	pila.cima = -1;
}


void agregar_valor(tpila &pila, int valor)
{
	
	if(pila_llena(pila))
	{
		cout << "pila llena" << endl;
	}
	else
	{
		pila.cima++;
		pila.datos[pila.cima] = valor;
	}
	
}

int extraer_valor(tpila &pila)
{
	int extraido;
	if(pila_vacia(pila))
	{
		extraido = 9999999;
	}
	else
	{
		extraido = pila.datos[pila.cima];
		pila.cima--;
	}
	
	return extraido;
	
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
	
	res = pila.cima == MAX - 1;
	
	return res;
}



int tope_pila(tpila pila)
{
	int res;
	
	if(pila_vacia(pila))
		res = -9999;
	else
		res = pila.datos[pila.cima];
	
	return res;
}


void termino_serie(int valor)
{
	tpila pila;
	int t1 = 1, t2 = 2, t3 = 3, i = 3;
	
	iniciar_pila(pila);
	
	
	agregar_valor(pila, t1);
	agregar_valor(pila, t2); 
	agregar_valor(pila, t3);
 	
	if(valor == 1)
	{
		cout << "termino vale: " << t1<<endl;
	}
	else
	{
		
		if(valor == 2)
		{
			cout << "termino vale: " << t2<<endl;
		}
		else{
			if(valor== 3 ) {
				cout<<"termino vale: "<<t3<<endl;
			}else{
				
				while(i < valor)
				{
					t2=extraer_valor(pila); //3
					t1=extraer_valor(pila); //2
					t3=t1+t2+extraer_valor(pila); // 2 + 3 + 1 => 6
					
					
					agregar_valor(pila, t1);
					agregar_valor(pila, t2);
					agregar_valor(pila, t3);
					i++;
				}
				cout << "termino vale: " << tope_pila(pila) << endl;	
			}
		}
	}
}


bool inverso(int n1, int n2){
	
	int mayor, menor, i, res;
	bool resultado;
	tpila pila;
	
	iniciar_pila(pila);
	
	if(n1>n2){
		mayor=n1;
		menor=n2;
	}else{
		mayor=n2;
		menor=n1;
	}
	
	while(mayor>0){
		agregar_valor(pila,mayor%10);
		mayor=mayor/10;
	}
	
	i=1;
	res=0;
	
	while(!pila_vacia(pila)){
		res=res+i*extraer_valor(pila);
		i=i*10;
	}
	
	resultado= res==menor;
	
	return resultado;
}
