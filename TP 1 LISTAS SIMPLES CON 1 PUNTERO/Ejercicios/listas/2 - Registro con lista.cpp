#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{
	char dato;
	pnodo sig;
};

typedef struct t_lista {
	pnodo inicio;
	int cant_caracteres;
};



void iniciar_lista (t_lista &lis);
void crear_nodo (pnodo &nuevo);
void agregar_inicio (t_lista &lis, pnodo nuevo, int limite);
pnodo quitar_final (t_lista &lis);
void mostrar_lista(t_lista lis);

void menu(char &opcion);

main()
{
	char opcion;
	t_lista lista;
	pnodo nuevo, eliminado;
	
	iniciar_lista(lista);
	system("pause");
	
	int limite=20;
	
	do
	{
		system("cls");
		menu(opcion);
		switch(opcion)
		{
		case '1':
			cout << ".....Agregar Inicio ......" << endl;
			crear_nodo(nuevo);
			agregar_inicio(lista, nuevo, limite);
			mostrar_lista(lista);
			break;

		case '2':
			cout << ".....Quitar Final ......" << endl;
			eliminado = quitar_final(lista);
			
			if(eliminado != NULL)
			{
				cout << "Eliminado " << eliminado->dato << endl;
				delete(eliminado);
				mostrar_lista(lista);
			}
			else
			   cout << "No se puede eliminar, lista vacia" << endl;
			break;
		case '3':
			cout << "..........Mostrando Lista.........." << endl;
			mostrar_lista(lista);
			cout << endl;
			break;
		case 's':
			cout << "...........FIN DEL PROGRAMA ~^.^~ ..........." << endl;
			break;
			
			default :
				cout << " OPCION INCORRECTA" << endl;
		}
		
		system("pause");
	}
	while(opcion != 's');
	
}

void iniciar_lista (t_lista &lis)
{
	cout << "Lista inicializada" << endl;
	
	lis.inicio = NULL;
	lis.cant_caracteres= 0;
}



void crear_nodo (pnodo &nuevo)
{
	cout << "Metodo Crear NODO" << endl;
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		cout << "Ingrese valor: ";
		cin >> nuevo->dato;
		nuevo->sig = NULL;
	}
	else
	   cout << "Memoria Insuficiente" << endl;
}


void agregar_inicio (t_lista &lis, pnodo nuevo, int lim)
{
	
	if(lis.cant_caracteres<lim){
		
	
		if(lis.inicio == NULL)
			lis.inicio  = nuevo;
		else
		{
			nuevo->sig = lis.inicio;
			lis.inicio = nuevo;
		}
		lis.cant_caracteres++;
	
	}else{
		cout<<"no se puede agregar mas elementos"<<endl; 
		delete(nuevo);
	}
}



pnodo quitar_final (t_lista &lis)
{
	pnodo extraido, i;
	if(lis.inicio == NULL) //extraccion de lista vacia
		extraido = NULL;
	else
	{
		if(lis.inicio->sig == NULL) //extraccion del unico nodo
		{
			extraido = lis.inicio;
			lis.inicio = NULL;
			lis.cant_caracteres=0;
		}else
		{
			for(i = lis.inicio ; (i->sig)->sig != NULL ; i = i->sig); //extraccion del ultimo nodo, posicionarse en el penultimo
			extraido = i->sig;
			i->sig = NULL;
			lis.cant_caracteres--;
		}
		
	}
	return extraido;
}



void mostrar_lista(t_lista lis)
{
	pnodo i;
	if(lis.inicio != NULL)
	{
		for(i = lis.inicio ; i != NULL ; i = i->sig) //se recorre la lista, nodo a nodo hasta que el puntero sea nulo
			cout << "  " << i->dato;
		
		cout << endl;
	}
	else
	   cout << "Lista Vacia";
	
	cout<<"\nTotal Caracteres: "<<lis.cant_caracteres<<endl;
}

void menu(char &opcion)
{
	cout << "****MENU****" << endl;
	cout << "1-Agregar Inicio" << endl;
	cout << "2-Quitar Final" << endl;
	cout << "3-Mostrar Lista" << endl;
	cout << "s-Salir" << endl;
	cout << "Elija opcion: ";
	cin >> opcion;
}

