#include <iostream>
#include <stdio.h>

using namespace std;

typedef FILE *parchivo; //definir el puntero archivo 1 sola vez


main(){
	
	parchivo fp;
	int pos;
	int num;
	fp=fopen("numeros.txt","wb+"); //lectura escritura - agregar datos al archivo binario

	cout<<"ingrese valores - ingreso finaliza con cero"<<endl;
	
	do{
		cout<<"ingrese un numero"<<endl;
		cin>>num;
		if(num!=0)
			fwrite(&num,sizeof(num),1,fp);
		
	} while(num!=0);
	
	rewind(fp); //reubica el puntero al inicio del archivo
	
	
	while(!feof(fp)) {
		
		fread(&num, sizeof(num),1,fp);
		
		if(!feof(fp)){
			pos=ftell(fp);//obtiene el numero de byte que se encuentra al puntero
			cout<<"la variable num contiene: "<<num<<endl;
			cout<<"byte nro: "<<pos<<endl;
		}
	}
	fclose(fp);

	system("pause");
	
}
