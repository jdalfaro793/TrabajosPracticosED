#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef FILE *parchivo;

typedef char tcad[50];

void cargar(parchivo f);
void mostrar_cadena(parchivo f);
void mostrar_palabra(parchivo f);
void mostrar_letra(parchivo f);

main(){
	parchivo fp;
	cargar(fp);
	cout<<"MOSTRANDO CADENA"<<endl;
	mostrar_cadena(fp);
	system("pause");
	cout<<"MOSTRANDO PALABRAS"<<endl;
	mostrar_palabra(fp);
	system("pause");
	cout<<"MOSTRANDO LETRAS"<<endl;
	mostrar_letra(fp);
	system("pause");
}


void cargar(parchivo f){
	tcad frase;
	
	f=fopen("fichero_arch3.dat","wb"); //escritura destructiva binario
	cout<<"ingrese cadena"<<endl;
	fflush(stdin);
	gets(frase); //cargamos la frase
	fwrite(&frase, sizeof(frase),1,f); //guardamos en el fichero
	fclose(f); //cerramos fichero
	
}
	
void mostrar_cadena(parchivo f){
	tcad frase;
	
	f=fopen("fichero_arch3.dat","rb"); //lectura binario
	
	while(!feof(f)){
		fread(&frase,sizeof(frase),1,f);
		if(!feof(f))
			cout<<frase<<endl;
	}
	fclose(f);
}


void mostrar_palabra(parchivo f){
	tcad frase;
	int cont=0;
	f=fopen("fichero_arch3.dat","rb"); //lectura binario
	
	while(!feof(f)){
		fscanf(f,"%s",&frase); //lee un dato de un archivo segun el formato determinado %s es cadena (archivo, modificador cadena, variable)
		cout<<frase<<endl;
		cont++;
	}
	cout<<"cantidad de palabras: "<<cont<<endl;
	fclose(f);
}

	
	
void mostrar_letra(parchivo f){
	char letra=' ';
	int cont=0;
	f=fopen("fichero_arch3.dat","rb"); //lectura binario
	
	while(!feof(f) && letra!='\0'){
		fread(&letra, sizeof(letra), 1, f);
		cout<<letra<<endl;
		if(letra!=' ')
			cont++;
	}
	cout<<"cantidad de letras: "<<cont<<endl;
	fclose(f);
	
}
