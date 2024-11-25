#include <iostream>
#include <stdio.h>

	using namespace std;

	typedef FILE *parchivo; //definir el puntero archivo 1 sola vez


	void cargar(parchivo fp);
	void mostrar(parchivo fp);



	main(){

		parchivo fichero;
		
		cargar(fichero);
		
		mostrar(fichero);
		
		
		
	}

	
	void cargar(parchivo fp){
		int a;
		int cont=5;	
		fp=fopen("letras.txt","ab"); //apertura del archivo en binario
		
		while(cont>0){
			cout<<"ingrese letra: ";
			cin>>a;
			
			fwrite(&a, sizeof(a), 1, fp); //acceso al archivo
			cont--;
		}
		
		fclose(fp); //cierre del archivo
	}
	
	
	
	void mostrar(parchivo fp){
		int a;
		
		fp=fopen("letras.txt","rb");
		
		if(fp==NULL)
			cout<<"EL ARCHIVO NO EXISTE"<<endl;
		else{
			while(!feof(fp)){//mientras que no sea final de archivo 
				fread(&a,sizeof(a),1,fp); //leer los registros tipo caracter
				
				if(!feof(fp)) //doble condicion que asegura que no es final de archivo
					cout<<a<<" ";
			}
			fclose(fp);
		}
	}
