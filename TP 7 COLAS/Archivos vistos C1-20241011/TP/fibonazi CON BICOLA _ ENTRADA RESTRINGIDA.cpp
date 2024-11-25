/*

a) determinar si un número entero es capicúa o no
ENTRADA RESTRINGIDA
*/

#include <iostream>

using namespace std;

const int MAX = 10;

typedef int tcontenedor[MAX];

typedef struct tcola
{
	tcontenedor datos1;
	tcontenedor datos2;
};


void iniciar_cola(tcola &cola);
void agregar_cola(tcola &cola, int nuevo);
bool cola_llena(tcola cola);
int  quitar_cola(tcola &cola, bool ultimo);
bool cola_vacia(tcola cola);
int primero_cola(tcola cola);
int ultimo_cola(tcola cola);
int siguiente(int indice);
int anterior(int indice);

int fibonaci(int numero);
main()
{
	
	int n;
	
	do{
		cout<<"ingrese numero: ";
		cin>>n;
	}while(n<0);

	cout<<"fibo: "<<fibonaci(n)<<endl;	
}

int fibonaci(int numero){
	int suma=0,i=2;
	tcola q;
	iniciar_cola(q);
	
	if(numero==1 || numero ==2)
		return 1;
	else{
		agregar_cola(q,1);
		agregar_cola(q,1);
		while(i<numero){
			
			suma=quitar_cola(q,false)+ultimo_cola(q);
			agregar_cola(q,suma);
			
	
			i++;
		}
		return quitar_cola(q,true);
	}
	
}
	//OPS BICOLA
	
	void iniciar_cola(tcola &cola)
	{
		cola.datos2[0] = MAX-1; //FRENTE
		cola.datos2[1] = MAX-1; //FINAL
	}
	
	
	void agregar_cola(tcola &cola, int  nuevo)
	{
		if(cola_llena(cola))
			cout << "cola llena" << endl;
		else
		{
			cola.datos2[1]=siguiente(cola.datos2[1]);
			
			if(cola.datos2[1] <= MAX-1)	
				cola.datos1[cola.datos2[1]]=nuevo;
			else{
				cola.datos2[ cola.datos2[1] - MAX ]=nuevo;
			}
			
		}
	}
	
	bool cola_llena(tcola cola)
	{  
		return siguiente(cola.datos2[1]) ==  cola.datos2[0];
	}
	
	int  quitar_cola(tcola &cola, bool ultimo)
	{
		int  extraido;
		
		if(cola_vacia(cola))
			extraido = -1; //valor arbitrario
		else
		{
			if(ultimo){
				
				
				if(cola.datos2[1]>=MAX)
					extraido=cola.datos2[cola.datos2[1]-MAX];
				else
					extraido=cola.datos1[cola.datos2[1]];
				
				cola.datos2[1]=anterior(cola.datos2[1]);
				
			}else{
				
				cola.datos2[0] = siguiente(cola.datos2[0]);
				if( cola.datos2[0] <=MAX-1 )
					extraido=cola.datos1[cola.datos2[0]];
				else
					extraido = cola.datos2[cola.datos2[0]-MAX];				
				
			}
			
		}
		return extraido;
	}
	
	bool cola_vacia(tcola cola)
	{
		return cola.datos2[1]==cola.datos2[0];
	}
	
	int  primero_cola(tcola cola)
	{
		int  primero;
		if(cola_vacia(cola))
			primero = -1; //valor arbitrario
		else
		{	
			if(siguiente(cola.datos2[0])<=MAX-1)
				primero=cola.datos1[cola.datos2[0]];
			else
				primero=cola.datos2[siguiente(cola.datos2[0])-MAX];
			
			
		}
		return primero;
	}
	
	int  ultimo_cola(tcola cola)
	{
		int  ultimo;
		if(cola_vacia(cola))
			ultimo = -1; //valor arbitrario
		else{
			if(cola.datos2[1]<=MAX-1)
				ultimo=cola.datos1[cola.datos2[1]];
			else
				ultimo = cola.datos2[cola.datos2[1]-MAX];
		}
		return ultimo;
	}
	
	
	int siguiente(int indice){
		indice++;	
		
		if(indice==2*MAX)
			indice=0;
		if(indice==MAX)
			indice=indice+2;
		
		return indice;
	}
		
		
		int anterior(int indice){
			indice--;
			
			if(indice==-1)
				indice=2*MAX-1;
			else{
				if(indice==MAX+1)
					indice=indice-2;
			}
			return indice;
		}
			
			
