#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAX_NOTAS=3;

typedef char tcad[20];

typedef int vnotas[MAX_NOTAS];

typedef struct tdomicilio {
	tcad calle;
	int numero;
	tcad barrio;
};

typedef struct testudiante {
	tcad legajo;
	tcad apellido;
	tcad nombre;
	float dni;
	tdomicilio domi;
	vnotas notas;
	float promedio_notas;
};


typedef struct tnodo *pnodo;
typedef struct tnodo
{
	testudiante alumno;
	
	pnodo sig;
};


void iniciar_lista(pnodo &lis);
void crear(pnodo &nuevo);
void cargar(testudiante &alumno);
void agregar_inicio (pnodo &lista, pnodo nuevo);
void menu(char &opcion);
void mostrar_lista(pnodo lis);
void mostrar(testudiante estudiante);

main()
{
	
	pnodo lista;
	pnodo nuevo;
	char opcion;
	
	iniciar_lista(lista);
	
	do
	{
		system("cls");
		menu(opcion);
		switch(opcion)
		{
			case '1': 
				cout<<".....Agregar valor ......"<<endl;
				crear(nuevo);
				agregar_inicio(lista, nuevo);
			break;
			
			case '7':
				cout<<".....Lista de estudiantes......"<<endl;
				mostrar_lista(lista);
				break;
				
			case 's': cout<<"Fin... :D"<<endl;
				break;
				
			default: cout<<"opcion invalida"<<endl;
		}
		
		system("pause");
		
	} while(opcion != 's');
	
}



void menu(char &opcion)
{
	cout << "****MENU****" << endl;
	cout << "1-Agregar Estudiante Inicio" << endl;

	cout << "7-Mostrar" << endl;
	
	cout << "s-Salir" << endl;
	cout << "Elija opcion: ";
	cin >> opcion;
}



//Inicialización
void iniciar_lista(pnodo &lis)
{
	lis=NULL;
}

//Creación del nodo
void crear(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingrese Datos del estudiante: "<<endl;
		cargar(nuevo->alumno);
		nuevo->sig=NULL;
	}
	else
	   cout<<"Memoria llena"<<endl;
}


void cargar(testudiante &alumno){
	bool valido=false;
	int min=4;
	alumno.promedio_notas=0;
	
	do{
		cout << "Ingrese legajo: ";
		fflush(stdin);
		gets(alumno.legajo);
		valido=strlen(alumno.legajo)>=min;
		
	} while(!valido);

	
	do{
		cout << "Ingrese apellido: ";
		fflush(stdin);
		gets(alumno.apellido);
		valido=strlen(alumno.apellido)>=min;
		
	} while(!valido);
	
	do{
	cout << "Ingrese nombre: ";
	fflush(stdin);
	gets(alumno.nombre);
	valido=strlen(alumno.nombre)>=min;
	
	} while(!valido);
	
	
	cout << "Ingrese dni: ";
	cin>>alumno.dni;
	
	do{
	cout << "Ingrese calle: ";
	fflush(stdin);
	gets(alumno.domi.calle);
	valido=strlen(alumno.domi.calle)>=min;
	
	} while(!valido);
	
	
	
	cout << "Ingrese numero: ";
	cin>>alumno.domi.numero;
	
	do{
	cout << "Ingrese barrio: ";
	fflush(stdin);
	gets(alumno.domi.barrio);
	valido=strlen(alumno.domi.barrio)>=min;
	
	} while(!valido);
	
	for (int i=0;i<=2;i++)
	{
		cout<<"ingrese nota "<<i+1<<": "<<endl;
		cin>>alumno.notas[i];
		alumno.promedio_notas+=alumno.notas[i];
	}
	
	
	alumno.promedio_notas=alumno.promedio_notas/MAX_NOTAS;
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

void mostrar_lista(pnodo lis)
{
	if(lis!=NULL)
	{
		//cout<<lis->dato<<"  ";
		mostrar(lis->alumno);
		mostrar_lista(lis->sig);
	}
}

void mostrar(testudiante estudiante)
{
	cout<<"...................................."<<endl;
	cout<<"\nlegajo: "<<estudiante.legajo<<endl;
	cout<<"apellido: "<<estudiante.apellido<<endl;
	cout<<"nombre: "<<estudiante.nombre<<endl;
	cout<<"dni:"<<estudiante.dni<<endl;
	
	cout<<"calle: "<<estudiante.domi.calle<<endl;
	cout<<"numero:"<<estudiante.domi.numero<<endl;	cout<<"barrio:"<<estudiante.domi.barrio<<endl;
	
	for (int i=0;i<=2;i++)
	{
		cout<<"nota "<<i+1<<": "<<estudiante.notas[i]<<endl;
	}
		
	cout<<"promedio total: "<<estudiante.promedio_notas<<endl;

}
