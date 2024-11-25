#include <iostream>
using namespace std;

const int MAX=20;


typedef int telementos[MAX];



typedef struct conjunto{
	telementos datos;
	int ocup;
};


void generar_conjunto_vacio(conjunto &c);

void union_conjunto(conjunto c1, conjunto c2, conjunto &c3);

void interseccion_conjunto(conjunto c1, conjunto c2, conjunto &c3);

void diferencia_de_conjuntos(conjunto c1, conjunto c2, conjunto &c3);

bool pertenece_conjunto(conjunto c, int valor);

void agregar_elemento(conjunto &c, int dato);

void mostrar_conjunto(conjunto c3);

int main(int argc, char *argv[]) {
	int c,valor;
	char respo;
	
	conjunto c1, c2, uni_on, inter_sec, differen;
	
	generar_conjunto_vacio(c1);
	generar_conjunto_vacio(c2);
	
	
	
	do{
		cout<<"CARGAR CONJUNTO 1: ";
		cin>>valor;
		agregar_elemento(c1,valor);
		
		cout<<"Agregar mas? s/n: ";
		cin>>respo;
	} while(respo!='n' );
	
	
	do{
		cout<<"CARGAR CONJUNTO 2: ";
		cin>>valor;
		agregar_elemento(c2,valor);
		
		cout<<"Agregar mas? s/n: ";
		cin>>respo;
	} while(respo!='n' );
	
	system("cls");
	
	union_conjunto(c1,c2, uni_on);
	interseccion_conjunto(c1,c2,inter_sec);
	diferencia_de_conjuntos(c1,c2,differen);
	
	
	
	
	cout<<"conjunto 1:";
	mostrar_conjunto(c1);
	cout<<endl;

	cout<<"conjunto 2:";
	mostrar_conjunto(c2);
	cout<<endl;
	
	
	cout<<"union ( u ) de conjuntos: "<<endl;
	mostrar_conjunto(uni_on);
	cout<<endl;
	
	cout<<"interseccion ( n ) de conjuntos: "<<endl;
	mostrar_conjunto(inter_sec);
	cout<<endl;
	cout<<"diferencia ( a - b ) de conjuntos: "<<endl;
	mostrar_conjunto(differen);
	
	
	
	return 0;
}





void generar_conjunto_vacio(conjunto &c){
	c.ocup=-1;
}

void union_conjunto(conjunto c1, conjunto c2, conjunto &c3){

	int i;
	
	generar_conjunto_vacio(c3);

	for(i=0;i<=c1.ocup;i++){
		agregar_elemento(c3,c1.datos[i]);
	}
	
	for(i=0;i<=c2.ocup;i++){
		if(!pertenece_conjunto(c1,c2.datos[i])){
			agregar_elemento(c3,c2.datos[i]);
		}
	}	
}

void interseccion_conjunto(conjunto c1, conjunto c2, conjunto &c3){
	
	int i;
	bool pertenece=false;

	generar_conjunto_vacio(c3);
	
	if(c1.ocup>c2.ocup){
		for(i=0; i <=c1.ocup;i++){
			if(pertenece_conjunto(c2, c1.datos[i])){
				agregar_elemento(c3,c1.datos[i]);
			}
		}
	}else{
		for(i=0; i <=c2.ocup;i++){
			if(pertenece_conjunto(c1, c2.datos[i])){
				agregar_elemento(c3,c2.datos[i]);
			}
		}
	}
}




bool pertenece_conjunto(conjunto c, int valor){
	bool pertenece=false;
	int i;

	for(i=0; i<=c.ocup && !pertenece; i++)
		if(c.datos[i]==valor)
			pertenece=true;
	return pertenece;
}


void agregar_elemento(conjunto &c, int dato){
	if(c.ocup==MAX){
		cout<<"no hay espacio"<<endl;
	}else{
		c.ocup++;
		c.datos[c.ocup]=dato;		
	}
}


void diferencia_de_conjuntos(conjunto c1, conjunto c2, conjunto &c3){
	int i;
	generar_conjunto_vacio(c3);
	for(i=0;i<=c1.ocup;i++){
		if(!pertenece_conjunto(c2, c1.datos[i]))
			agregar_elemento(c3,c1.datos[i]);
	}
}

void mostrar_conjunto(conjunto c3){
	int i;
	if(c3.ocup==-1){
		cout<<"{ }"<<endl;
	}else{
		cout<<"{ ";
		for(i=0;i<=c3.ocup;i++){

			cout<<c3.datos[i];
			if(i!=c3.ocup)
				cout<<" , ";
		}
		
		cout<<" }"<<endl;
	}
}
