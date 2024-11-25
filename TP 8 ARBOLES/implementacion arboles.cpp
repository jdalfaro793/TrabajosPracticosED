#include <iostream>
using namespace std;


typedef struct tnodo *pnodo;
typedef struct tnodo {
	int dato;
	pnodo izq;
	pnodo der;
};

void iniciar_arbol(pnodo &a);
void crear_nodo(pnodo &nuevo);
void insercion(pnodo &a, pnodo nuevo);
void preorden(pnodo a);
void enorden(pnodo a);
void enorden2(pnodo a);
void posorden(pnodo a);
bool busqueda_basico(pnodo a, int buscado);
//--
int contar_nodos(pnodo a);
int contar_hojas(pnodo a);
int suma_nodos(pnodo a);
int calcular_altura(pnodo a);
bool determinar_binario_completo(pnodo a);
int contar_repetidos(pnodo a, int buscado);
int min_max(pnodo a, bool max);

void menu(int &op);

main(){
	pnodo arbol, nuevo;
	int opc;
	int valor;
	
	iniciar_arbol(arbol);
	
	do{
		system("cls");
		menu(opc);
		
		switch(opc){
		case 1: 
			crear_nodo(nuevo);
			insercion(arbol, nuevo);
			break;
		case 2:
			preorden(arbol);
			cout<<endl;
			break;
		case 3: 
			cout<<"orden asc"<<endl;
			enorden(arbol);
			cout<<endl;
			cout<<"orden desc"<<endl;
			enorden2(arbol);
			cout<<endl;
			break;
		case 4: 
			posorden(arbol);
			cout<<endl;
			break;
		case 5:
			cout<<"preorden"<<endl;
			preorden(arbol);
			cout<<endl;
			cout<<"en orden"<<endl;
			enorden(arbol);
			cout<<endl;
			cout<<"posorden"<<endl;
			posorden(arbol);
			cout<<endl;
			break;	
		case 6: 
			cout<<"cantidad nodos: "<<contar_nodos(arbol)<<endl;
			cout<<"cantidad hojas: "<<contar_hojas(arbol)<<endl;
			cout<<"suma de nodos: "<<suma_nodos(arbol)<<endl;
			cout<<"altura: "<<calcular_altura(arbol)<<endl;
		
			if(determinar_binario_completo(arbol))
				cout<<"es binario completo"<<endl;
			else
				cout<<"no es binario completo"<<endl;
			
			break;
		case 7:
			cout<<"ingrese valor: ";
			cin>>valor;
			if(busqueda_basico(arbol,valor))
				cout<<"valor encontrado"<<endl;
			else
				cout<<"valor no existe"<<endl;
			break;
		case 8:
			cout<<"ingrese valor: ";
			cin>>valor;

			cout<<"valor se repite: "<<contar_repetidos(arbol, valor)<<" veces"<<endl;

			break;
			
		case 9:
			cout<<"min: "<<min_max(arbol, false) <<endl;
			cout<<"max: "<<min_max(arbol, true) <<endl;
			break;
		case 0:
			cout<<"fin del programa"<<endl;
			break;
			
		default:
			cout<<"opcion invalida"<<endl;
		};
		
		system("pause");
	} while(opc!=0);
	

	
}

void iniciar_arbol(pnodo &a){
	a=NULL;
}

void crear_nodo(pnodo &nuevo){
	
	nuevo=new tnodo;

	if(nuevo!=NULL){
		cout<<"ingrese numero: ";
		cin>>nuevo->dato;
		nuevo->izq=NULL;
		nuevo->der=NULL;
	}else cout<<"memoria insuficiente"<<endl;
	
}
	
void insercion(pnodo &a, pnodo nuevo) {
	if (a == NULL)
		a = nuevo;
	else 
		if (nuevo->dato < a->dato)
			insercion(a->izq, nuevo);  // insertar en el subárbol izquierdo
		else 
			insercion(a->der, nuevo);  // insertar en el subárbol derecho
	
}

//no permite valores repetidos y tiene arbol inverso
/*void insercion(pnodo &a, pnodo nuevo) {
	if (a == NULL)
		a = nuevo;
	else {
		if(contar_repetidos(a,nuevo->dato)==0)
		{
			if (nuevo->dato > a->dato)
				insercion(a->izq, nuevo);  // Insertar en el subárbol izquierdo
			else 
				insercion(a->der, nuevo);  // Insertar en el subárbol derecho
		}else{
			delete(nuevo);
		}
	}
}*/
	
	
void preorden(pnodo a){
	if(a!=NULL){
		cout<<a->dato<<" ";
		preorden(a->izq);
		preorden(a->der);
	}
}
void enorden(pnodo a){
	if(a!=NULL){
		enorden(a->izq);
		cout<<a->dato<<" ";
		enorden(a->der);
	}
}

void enorden2(pnodo a){
	if(a!=NULL){
		enorden2(a->der);
		cout<<a->dato<<" ";
		enorden2(a->izq);
	}
}

void posorden(pnodo a){
	if(a!=NULL){
		posorden(a->izq);
		posorden(a->der);
		cout<<a->dato<<" ";
	}
}
	
void menu(int &op){
	cout<<"1- ingresar nodo"<<endl;
	cout<<"2- mostrar pre-orden"<<endl;
	cout<<"3- mostrar en-orden"<<endl;
	cout<<"4- mostrar pos-orden"<<endl;
	cout<<"5- mostrar 3 ordenes"<<endl;
	cout<<"6- operaciones"<<endl;
	cout<<"7- buscar nodo"<<endl;
	cout<<"8- contar repetidos"<<endl;
	cout<<"9- mostrar min y max"<<endl;
	cout<<"0- salir"<<endl;
	cout<<"ingrese opcion: ";
	cin>>op;
}

	
int contar_nodos(pnodo a){
	int suma=0;
	if(a!=NULL){
		suma=1;
		suma=contar_nodos(a->izq)+contar_nodos(a->der)+suma;
	}
	return suma;
}
	
	
//ok	
int contar_hojas(pnodo a){
	if(a==NULL){
		return 0;
	}else{
		if(a->izq==NULL && a->der==NULL)
			return 1;
		else{
			return contar_hojas(a->izq)+contar_hojas(a->der);
		}
	}
}

int suma_nodos(pnodo a){
	int suma=0;
	if(a!=NULL){
		suma= a->dato + suma_nodos(a->izq)+suma_nodos(a->der);
	}
	return suma;
}

int calcular_altura(pnodo a){
	int altura_izq = 0;
	int altura_der = 0;
	
	
	if(a==NULL)
		return 0;
	else
		if (a != NULL) {
			altura_izq = calcular_altura(a->izq);
			altura_der = calcular_altura(a->der);
			
			if (altura_izq > altura_der)
				return altura_izq+1;
			else
				return altura_der+1;
	}
		return 0;
}

bool determinar_binario_completo(pnodo a){
	bool res=true;
	if(a!=NULL)
	{
		res = (a->izq!=NULL && a->der!=NULL) || (a->izq==NULL && a->der==NULL);
		
		if(res){
			res = determinar_binario_completo(a->izq) && determinar_binario_completo(a->der);
		}
		else{
			return res;
		}	
	}
	return res;
}
	
	
bool busqueda_basico(pnodo a, int buscado){
	bool res=false;
	
	if(a!=NULL){
		res=a->dato==buscado;
		
		if(res==false){
			res=busqueda_basico(a->izq,buscado);
			if(res==false)
				res=busqueda_basico(a->der, buscado);
		}
	}
	return res;
}

//modificar algoritmo basico de busqueda para contar repeticiones	
int contar_repetidos(pnodo a, int buscado){
	int s=0;
	
	if(a!=NULL){
		if(a->dato==buscado)
			s=1;
		
			s=s + contar_repetidos(a->izq,buscado);
			s=s + contar_repetidos(a->der, buscado);
	}
	return s;
}
	
	int min_max(pnodo a, bool max){
		
		if(a!=NULL){
			if(max){
				if(a->der==NULL)
					return a->dato;
				else
					return min_max(a->der, max);
			}else{
				if(a->izq==NULL)
					return a->dato;
				else
					return min_max(a->izq, max);
			}
		}
		
		return 0;
	}
