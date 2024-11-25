#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{
    char dato;
    pnodo sig;
};


void iniciar_lista (pnodo &lista);
void crear_nodo (pnodo &nuevo);
void agregar_inicio (pnodo &lista, pnodo nuevo);
void agregar_final (pnodo &lista, pnodo nuevo);
void agregar_final_norep (pnodo &lista, pnodo nuevo);

void agregar_en_orden(pnodo &lista, pnodo nuevo);
pnodo quitar_inicio (pnodo &lista);
pnodo quitar_final (pnodo &lista);
pnodo quitar_nodo_especifico(pnodo &lista, char buscado);
bool buscar_nodo(pnodo lista, char valor);
void mostrar_datos(pnodo lista);
void mostrar_datos_circular(pnodo lista);
void menu(char &opcion);
void liberar_nodo (pnodo &nuevo);

main()
{

    pnodo lista;
    pnodo nuevo, eliminado;
    char opcion, paraEliminar, paraBuscar;
    bool busqueda;

    iniciar_lista(lista);
    system("pause");

    do
    {
        system("cls");
        menu(opcion);
        switch(opcion)
        {
        case '1':
            cout << ".....Agregar Inicio ......" << endl;
            crear_nodo(nuevo);
            agregar_inicio(lista, nuevo);
            mostrar_datos(lista);
            break;
        case '2':
            cout << ".....Agregar Final ......" << endl;
            crear_nodo(nuevo);
            agregar_final(lista, nuevo);
            mostrar_datos(lista);
            break;
        case '3':
            cout << ".....Agregar En Orden ......" << endl;
            crear_nodo(nuevo);
            agregar_en_orden(lista, nuevo);
            mostrar_datos(lista);
            break;
        case '4':
            cout << ".....Quitar Inicio ......" << endl;

            eliminado = quitar_inicio(lista);

            if(eliminado != NULL)
            {
                cout << "Eliminado " << eliminado->dato << endl;
                delete(eliminado);
                mostrar_datos(lista);
            }
            else
                cout << " No se puede eliminar, lista vacia" << endl;

            break;
        case '5':
            cout << ".....Quitar Final ......" << endl;
            eliminado = quitar_final(lista);

            if(eliminado != NULL)
            {
                cout << "Eliminado " << eliminado->dato << endl;
                delete(eliminado);
                mostrar_datos(lista);
            }
            else
                cout << " No se puede eliminar, lista vacia" << endl;
            break;
        case '6':
            cout << ".....Quitar Nodo en Especifico ......" << endl;
            cout << "Ingrese valor a eliminar: " ;
            cin >> paraEliminar;
            eliminado = quitar_nodo_especifico(lista, paraEliminar);

            if(eliminado != NULL)
            {
                cout << "Eliminado " << eliminado->dato << endl;
                delete(eliminado);
                mostrar_datos(lista);
            }
            else
                cout << " No se puede eliminar, lista vacia" << endl;
            break;
        case '7':
            cout << "..........Mostrando Lista.........." << endl;
            mostrar_datos(lista);
            cout << endl;
            break;
        case '8':
            cout << "......Buscar valor..........." << endl;
            cout << "Ingrese valor a buscar: " ;
            cin >> paraBuscar;
            busqueda = buscar_nodo(lista, paraBuscar);
            if(busqueda == true)
                cout << "Valor encontrado: " << paraBuscar << endl;
            else
                cout << "Valor no encontrado..." << endl;
            break;
			
		case '9':
			cout << ".....Agregar Final Norep ......" << endl;
			crear_nodo(nuevo);
			agregar_final_norep(lista, nuevo);
			mostrar_datos_circular(lista);
			break;
        case 's':
            cout << "...........FIN DEL PROGRAMA ^_^ ..........." << endl;
            break;

        default :
            cout << " OPCION INCORRECTA" << endl;
        }

        system("pause");
    }
    while(opcion != 's');

}

void iniciar_lista (pnodo &lista)
{
    cout << "Lista inicializada" << endl;

    lista = NULL;
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

void agregar_inicio (pnodo &lista, pnodo nuevo)
{
    if(lista == NULL)
        lista = nuevo;
    else
    {
        nuevo->sig = lista;
        lista = nuevo;
    }
}

void agregar_final (pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(lista == NULL)
        lista = nuevo;
    else
    {
        for(i = lista ; i->sig != NULL ; i = i->sig);
        i->sig = nuevo;
    }
}


void agregar_final_norep (pnodo &lista, pnodo nuevo)
{
	pnodo i;
	bool encontrado=false;
	if(lista == NULL)
	{
		lista = nuevo;
		lista->sig=lista;
	}
	else
	{
		if(lista->dato==nuevo->dato)
			encontrado=true;
		else
			for(i=lista;i->sig!=lista && !encontrado; i=i->sig)
				if(i->sig->dato==nuevo->dato)
					encontrado=true;
		
		if(encontrado){
			cout<<"ya existe el nodo"<<endl;
			delete(nuevo);
		}else{
			for(i=lista;i->sig!=lista;i=i->sig);
			i->sig=nuevo;
			nuevo->sig=lista;
		}
		
		
	}
}

void agregar_en_orden(pnodo &lista, pnodo nuevo)
{
    pnodo i;
    if(lista == NULL) //lista vacia
        lista = nuevo;
    else
    {
        if(nuevo->dato < lista->dato) //Agregar al inicio, el nuevo valor es menor que el 1ero
        {
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            for(i = lista ;
                    i->sig != NULL &&
                    (i->sig)->dato < nuevo->dato ;
                    i = i->sig); //agregar al medio o al final
            nuevo->sig = i->sig;
            i->sig = nuevo;
        }
    }
}

pnodo quitar_inicio (pnodo &lista)
{
    pnodo extraido;
    if(lista == NULL) //extraccion de lista vacia
        extraido = NULL;
    else
    {
        extraido = lista;  //extraccion del primer nodo
        lista = lista->sig;
        extraido->sig = NULL;
    }
    return extraido;
}


pnodo quitar_final (pnodo &lista)
{
    pnodo extraido, i;
    if(lista == NULL) //extraccion de lista vacia
        extraido = NULL;
    else
    {
        if(lista->sig == NULL) //extraccion del unico nodo
        {
            extraido = lista;
            lista = NULL;
        }else
        {
            for(i = lista ; (i->sig)->sig != NULL ; i = i->sig); //extraccion del ultimo nodo, posicionarse en el penultimo
            extraido = i->sig;
            i->sig = NULL;
        }
    }
    return extraido;
}

pnodo quitar_nodo_especifico(pnodo &lista, char buscado)
{
    pnodo extraido, i;
    if(lista == NULL) //extraccion de lista vacia
        extraido = NULL;
    else
    {
        if(lista->dato == buscado) //extraccion del primer nodo
        {
            extraido = lista;
            lista = extraido->sig;
            extraido->sig = NULL;
        }
        else
        {
            for(i = lista ; i->sig != NULL && buscado != (i->sig)->dato ; i = i->sig);
            if(i->sig != NULL) //extraccion del medio o final
            {
                extraido = i->sig;
                i->sig = extraido->sig;
                extraido->sig = NULL;
            }
            else
                extraido = NULL; //valor no encontrado
        }
    }
    return extraido;
}

bool buscar_nodo(pnodo lista, char valor)
{
    pnodo i;
    bool encontrado = false;


    if(lista != NULL)
    {
        for(i = lista ; i != NULL && !encontrado; i = i->sig)
        {
            if(i->dato == valor)    //se recorre nodo a nodo hasta que el puntero sea nulo o se detecte el valor
                encontrado = true;
        }
    }
    return encontrado;
}

void mostrar_datos(pnodo lista)
{
    pnodo i;
    if(lista != NULL)
    {
        for(i = lista ; i != NULL ; i = i->sig) //se recorre la lista, nodo a nodo hasta que el puntero sea nulo
            cout << "  " << i->dato;
        cout << endl;
    }
    else
        cout << "Lista Vacia";
}

void mostrar_datos_circular(pnodo lista)
{
	pnodo i;
	if(lista != NULL)
	{
		
		cout<<lista->dato;
		for(i = lista ; i->sig != lista; i = i->sig) //se recorre la lista, nodo a nodo hasta que el puntero sea nulo
			cout << "  " << i->sig->dato;
		cout << endl;
	}
	else
	   cout << "Lista Vacia";
}


void menu(char &opcion)
{
    cout << "****MENU****" << endl;
    cout << "1-Agregar Inicio" << endl;
    cout << "2-Agregar Final" << endl;
    cout << "3-Agregar en Orden" << endl;
    cout << "4-Quitar Inicio" << endl;
    cout << "5-Quitar Final" << endl;
    cout << "6-Quitar Nodo Especifico" << endl;
    cout << "7-Mostrar" << endl;
    cout << "8-Buscar valor" << endl;
	cout << "9-Agregar Final NOREP" << endl;
    cout << "s-Salir" << endl;
    cout << "Elija opcion: ";
    cin >> opcion;
}

//eliminar solo un nodo
void liberar_nodo (pnodo &nuevo)
{
	delete(nuevo);
	nuevo=NULL;
}
