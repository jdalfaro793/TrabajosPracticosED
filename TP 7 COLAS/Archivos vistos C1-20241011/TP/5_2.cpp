#include <iostream>
using namespace std;


const int MAX=10;

typedef char tcontenedor[MAX];
typedef struct tindicador{
	int frente;
	int final;
};
typedef struct tcola{
	tindicador ind;
	tcontenedor datos;	
};

//falta main y declaracion de modulos, pero los modulos solicitados están

void iniciar_cola(tcola &q){
	q.ind.frente=0;
	q.ind.final=0;
}
	
void agregar_cola(tcola &q, char nuevo){
	
	if(cola_llena(q))
		cout<<"cola llena"<<endl;
	else{
		q.ind.final=siguiente(q.ind.final);
		q.datos[q.ind.final]=nuevo;
	}
}


bool cola_llena(tcola q){
	return siguiente(q.ind.final)==q.ind.frente;
}

	

int siguiente(int indice){
	if(indice==MAX-1){
		return 0;
	}else{
		return indice+1;
	}
}
