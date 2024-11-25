#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef char tcad[50];

struct talumno
{
    int libreta;
    tcad nombre;
	tcad apellido;
	tcad carrera;
	int comision;
	
};

typedef FILE *parchivo;

//MANIPULACION DEL REGISTRO POR SEPARADO
void carga_registro(talumno &alumno);
void mostrar_registro(talumno alumno);

void alta(parchivo alumnos);
void mostrar(parchivo alumnos); //todos los datos del archivo
bool buscar_archivo(parchivo alumnos, int buscado);
void menu(int &op);
void borrar(parchivo alumnos, int buscado);
void modificar(parchivo alumnos, int buscado);
void listar_carrera(parchivo alumnos, tcad carrera);
main()
{
    parchivo estudiantes;
	int lu,op;
	tcad carrera;
	
	do{
		system("cls");
		menu(op);
		switch(op){
		case 1: 
			alta(estudiantes); 
			break;
			
		case 2: 
			mostrar(estudiantes);
			break;
			
		case 3: 
			cout<<"ingrese lu :";
			cin>>lu;
			borrar(estudiantes, lu);
			break;
			
		case 4:
			cout<<"ingrese lu: ";
			cin>>lu;
			modificar(estudiantes, lu);
			break;
			
		case 5: 
			cout<<"ingrese lu: ";
			cin>>lu;
			if(buscar_archivo(estudiantes, lu))
				cout<<"el alumno existe"<<endl;
			else
				cout<<"el alumno no existe"<<endl;
			break;
			
		case 6:
			cout<<"ingrese carrera: ";
			fflush(stdin);
			gets(carrera);
			listar_carrera(estudiantes, carrera);
			
		case 7:
			cout<<"fin del programita.."<<endl;
			break;
		default:
			cout<<"opcion incorrecta"<<endl;
		}
		system("pause");
	} while(op!=7);
}

void carga_registro(talumno &alumno){
	fflush(stdin);//fflush extra por limpieza de archivos abiertos
	cout<<"ingrese lu: ";
	cin>>alumno.libreta;
	
	cout<<"ingrese nombre: ";
	fflush(stdin);
	gets(alumno.nombre);
	
	cout<<"ingrese apellido: ";
	fflush(stdin);
	gets(alumno.apellido);
	
	cout<<"ingrese carrera: ";
	fflush(stdin);
	gets(alumno.carrera);
	
	cout<<"ingrese comision: ";
	cin>>alumno.comision;
	
}


void mostrar_registro(talumno alumno){
	cout<<"\nLU: "<<alumno.libreta<<endl;
	cout<<"Nombre: "<<alumno.nombre<<endl;
	cout<<"Apellido: "<<alumno.apellido<<endl;
	cout<<"Carrera: "<<alumno.carrera<<endl;
	cout<<"Comision: "<<alumno.comision<<endl;
}

void alta(parchivo alumnos){
	talumno a;
	int cantidad;
	alumnos=fopen("alumnos.txt","ab");
	cout<<"cuantos registros desea guardar: ";
	cin>>cantidad;
	while(cantidad>0){
		carga_registro(a);
		fwrite(&a, sizeof(a),1,alumnos);
		cantidad--;
	}
	fclose(alumnos);
}


void mostrar(parchivo alumnos){
	talumno a;
	alumnos=fopen("alumnos.txt","rb");
	if(alumnos==NULL)
		cout<<"Archivo inexistente"<<endl;
	else{
		while(!feof(alumnos)){
			fread(&a,sizeof(a),1,alumnos);
			if(!feof(alumnos))
				mostrar_registro(a);
		}
	}
	fclose(alumnos);
}


bool buscar_archivo(parchivo alumnos, int buscado){
	
	bool existe=false;
	talumno a;
	alumnos=fopen("alumnos.txt","rb");
	if(alumnos!=NULL)
		while(!feof(alumnos) && !existe){
			fread(&a, sizeof(a), 1, alumnos);
			if(a.libreta==buscado)
				existe=true;
		}
		
	fclose(alumnos);
	return existe;
}
	

	
void menu(int &op){
	cout<<"********MENU********"<<endl;
	cout<<"1-alta de alumnos"<<endl;
	cout<<"2-mostrar"<<endl;
	cout<<"3-borrar"<<endl;
	cout<<"4-modificar"<<endl;
	cout<<"5-buscar"<<endl;
	cout<<"6-listar x carrera"<<endl;
	cout<<"7-salir"<<endl;
	cout<<"Ingrese opcion: ";
	cin>>op;
}
	


void borrar(parchivo alumnos, int buscado){
	talumno a;
	parchivo aux;
	
	bool band=false;
	
	alumnos=fopen("alumnos.txt","rb");
	aux=fopen("temporal.txt","wb");
	
	if(alumnos!=NULL){
		while(!feof(alumnos)){
			fread(&a,sizeof(a),1,alumnos);
			if(!feof(alumnos) && a.libreta!=buscado)
				fwrite(&a, sizeof(a), 1, aux);
		}
	}	
	
	fclose(aux);
	fclose(alumnos);
	
	if(remove("alumnos.txt")==0){
		cout<<"eliminado";
		if(rename("temporal.txt", "alumnos.txt")==0)
			cout<<" exitosamente!"<<endl;
		else
			cout<<", no se renombró archivo temporal..."<<endl;
	}else{
		cout<<"error al eliminar"<<endl;
	}
}

void modificar(parchivo alumnos, int buscado){
	talumno alu;
	bool existe=false;
	alumnos=fopen("alumnos.txt","rb+");
	if(alumnos!=NULL){
		while(!feof(alumnos) && !existe){
			fread(&alu, sizeof(alu), 1, alumnos);
			if(alu.libreta==buscado)
				existe=true;
		}
		
		
		if(existe){
			fseek(alumnos, -sizeof(alu),1); //ubica el puntero en una posicion especifica del archivo

			carga_registro(alu);
			
			fwrite(&alu, sizeof(alu), 1, alumnos);
		}else
		   cout<<"el registro no existe"<<endl;
		

	}
	fclose(alumnos);
}
void listar_carrera(parchivo alumnos, tcad carrera){
	
	talumno alu;
	alumnos=fopen("alumnos.txt","rb+");
	if(alumnos!=NULL){
		while(!feof(alumnos)){
			fread(&alu, sizeof(alu), 1, alumnos);
			if(strcmp(carrera, alu.carrera)==0 && !feof(alumnos))
				mostrar_registro(alu);
		}
	}
	
	fclose(alumnos);
}
