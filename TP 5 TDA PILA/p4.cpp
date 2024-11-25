#include <iostream>
#include <math.h>
using namespace std;

typedef struct tpila *ppila;

typedef struct tpila {
	int dato;
	ppila ant;
	ppila sig;
};

void iniciar_pila(ppila &p);
void crear_nodo(ppila &nuevo, int valor);
void agregar_pila(ppila &p, int nuevo);
int quitar_pila(ppila &p);
bool pila_vacia(ppila p);

int main() {
	ppila p;
	int num, n,i, numInvertido = 0;
	
	cout << "Ingrese un numero: ";
	cin >> num;
	
	n = num; // Guardamos el número original
	iniciar_pila(p);
	
	// Insertar los dígitos en la pila
	while (num > 0) {
		agregar_pila(p, num % 10);  // Se extrae el dígito menos significativo
		num = num / 10;
	}
	
	i=0;

	while (pila_vacia(p)!=true)
	{
		numInvertido=numInvertido + quitar_pila(p)*pow(10.0,i);
		i++;
	}	
	// Comparar el número original con el número invertido
	cout << "n: " << n << " - s: " << numInvertido << endl;
	
	if (n == numInvertido) {
		cout << "ES CAPICUA" << endl;
	} else {
		cout << "NO ES CAPICUA" << endl;
	}
	
	return 0;
}

void iniciar_pila(ppila &p) {
	p = NULL;
}

void crear_nodo(ppila &nuevo, int valor) {
	nuevo = new tpila;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->ant = NULL;
		nuevo->sig = NULL;
	}
}

void agregar_pila(ppila &p, int valor) { //agregar final
	ppila i,nuevo;
	crear_nodo(nuevo, valor);
	
	if (nuevo == NULL) {
		cout << "PILA LLENA" << endl;
	} else {
		if(p==NULL){
			p=nuevo;
		}else{
			for(i=p;i->sig!=NULL;i=i->sig);
			i->sig=nuevo;
			nuevo->ant=i;
		}
	}
}

int quitar_pila(ppila &p) { // quitar final
	int res;
	ppila i,ext;
	
	if (pila_vacia(p)) {
		return -1;  // Indicador de pila vacía
	} else {
		
		if(p->sig==NULL){
		
			ext=p;
			p=NULL;
		}
		else{
			for(i=p;i->sig!=NULL; i=i->sig);
			ext=i;
			
			ext->ant->sig=NULL;
			ext->ant=NULL;
		}
		res=ext->dato;
		
		delete(ext);	
	}
	return res;
}

bool pila_vacia(ppila p) {
	return p == NULL;
}
