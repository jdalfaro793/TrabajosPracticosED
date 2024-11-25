#include <iostream>

using namespace std;

typedef struct tnodo *pnodo; //puntero
typedef struct tnodo
{
	int dato;
	int acum; 
	pnodo sig;
};

void iniciar_lista (pnodo &lista);
void crear_nodo (pnodo &nuevo);
void agregar_final (pnodo &lista, pnodo &nuevo);

pnodo quitar_nodo_especifico(pnodo &lista, int buscado);

pnodo buscar_nodo(pnodo lista, int valor);
void mostrar_lista(pnodo inicio, int opcion);
void menu(char &op);

main()
{
	char opc;
	int tipo_lista,eliminar;
	pnodo lista;
	pnodo nuevo, eliminado;
	
	iniciar_lista(lista);
	
	do
	{
		system("cls");
		menu(opc);
		
		switch(opc){
		case 'a': 
			crear_nodo(nuevo);
			agregar_final (lista, nuevo);
			cout<<endl;
			break;
		case 'b':
			
			cout << "Ingrese valor a eliminar: " ;
			cin >> eliminar;
			eliminado = quitar_nodo_especifico(lista, eliminar);
			
			if(eliminado != NULL)
			{
				cout << "Eliminado " << eliminado->dato << endl;
				if(eliminado->acum==0){
					delete(eliminado);
					cout<<"Eliminado definitivamente..."<<endl;
				}
				
			}
			else
			   cout << " No se puede eliminar, lista vacia" << endl;
			break;

			break;
		case 'c': 
			cout <<"1) normal, 2) inverso"<<endl;
			cin>>tipo_lista;
			
			if(tipo_lista!=1 && tipo_lista!=2) cout<<"error de opcion"<<endl;
			else mostrar_lista(lista, tipo_lista);
			cout<<endl;		
			break;
		case 'd':
			cout<<"Fin..."<<endl;
			break;
		}
		system("pause");
	} while(opc!='d');
	
}


void iniciar_lista (pnodo &lista)
{
	lista=NULL;
}
	
void crear_nodo(pnodo &nuevo)
{
	cout << "crear_nodo" << endl;
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		cout << "ingrese dato: ";
		cin >> nuevo->dato;
		
		nuevo->acum = 1;
		nuevo->sig = NULL;
	}
	else
	{
		cout << "memoria insuficiente" << endl;
	}
}

void agregar_final (pnodo &lista, pnodo &nuevo){
	pnodo i;
	
	if(lista==NULL){
		//agregar primero
		lista=nuevo;
	}else{
		
		i=buscar_nodo(lista,nuevo->dato);
		
		if(i!=NULL){
			i->acum++;
			delete(nuevo);
			nuevo=NULL;
		}else{
			//agregar al ultimo de la lista
			for(i=lista;i->sig!=NULL; i=i->sig);
			i->sig=nuevo;
		}
	}
}


void mostrar_lista(pnodo inicio, int opcion){
	if (inicio==NULL){
		cout << "Lista Vacia" << endl;
	} else {
		if (inicio->sig==NULL){
			cout <<"__________"<<endl;
			cout <<inicio->dato<<endl;
			cout <<"acum: "<<inicio->acum<<endl;
		} else {
			if(opcion==1){
				cout <<"__________"<<endl;
				cout <<inicio->dato<<endl;
				cout <<"acum: "<<inicio->acum<<endl;
				
				mostrar_lista(inicio->sig,opcion);				
			}else{
				mostrar_lista(inicio->sig,opcion);
				
				cout <<"__________"<<endl;
				cout <<inicio->dato<<endl;
				cout <<"acum: "<<inicio->acum<<endl;
			}
		}
	}
}
		
pnodo buscar_nodo(pnodo lista, int valor){
	pnodo i=NULL;
	if(lista!=NULL){
		for(i=lista;i!=NULL && i->dato!=valor;i=i->sig);
	}		
	return i;
}
			
	
pnodo quitar_nodo_especifico(pnodo &lista, int buscado)
{
	pnodo extraido, i;
	if(lista == NULL) //extraccion de lista vacia
		extraido = NULL;
	else
	{
		if(lista->dato == buscado) //extraccion del primer nodo
		{
			
			extraido = lista;
			extraido->acum--;
			
			if(extraido->acum==0){
				lista = extraido->sig;
				extraido->sig = NULL;
			}
		}
		else
		{
			for(i = lista ; i->sig != NULL && buscado != (i->sig)->dato ; i = i->sig);
			if(i->sig != NULL) //extraccion del medio o final
			{
				extraido = i->sig;
				extraido->acum--;
				if(extraido->acum==0){
					i->sig = extraido->sig;
					extraido->sig = NULL;
				}
			}
			else
			   extraido = NULL; //valor no encontrado
		}
	}
	return extraido;
}
	
void menu(char &op)
{
	cout << "****MENU****" << endl;
	cout << "a-Agregar valor al Final" << endl;
	cout << "b-Quitar valor especifico" << endl;
	cout << "c-Mostrar lista recursivamente" << endl;
	cout << "d-Salir" << endl;
	cout << "Elija opcion: ";
	cin >> op;
}
			

