#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef char tcad[50];
struct tmedico
{
    int matricula;
    tcad apynom;
    tcad especialidad;
};
typedef FILE *parchivo;
void alta (parchivo medicos);
void carga(tmedico &m);
void mostrar(parchivo medicos);
bool buscar_archivo(parchivo medicos, int buscado);
main()
{
    parchivo medicos;
    alta(medicos);
    mostrar(medicos);
    system("pause");
}

void carga (tmedico &m)
{
    cout << "Ingrese matricula: ";
    cin >> m.matricula;
    cout << "Ingrese nombre: ";
    fflush(stdin);
    gets(m.apynom);
    cout << "Ingrese especialidad: ";
    fflush(stdin);
    gets(m.especialidad);
}


void alta (parchivo medicos)
{
    tmedico m;
    int cantidad;
    medicos = fopen("medicos.txt", "ab+");
    cout << "Cuántos registros desea guardar: ";
    cin >> cantidad;
    while (cantidad > 0)
    {
        carga(m);
		
		if(buscar_archivo(medicos, m.matricula)){
			cout<<"ya existe"<<endl;
			system("pause");
		}else{
				fwrite(&m, sizeof(m), 1, medicos);
				cantidad--;	
		}

    }
    fclose(medicos);
}

bool buscar_archivo(parchivo medicos, int buscado)
{
	bool existe = false;
	tmedico m;
	rewind(medicos);  // Mover el puntero al inicio del archivo
	while (!feof(medicos) && !existe)
	{
		fread(&m, sizeof(m), 1, medicos);
		if (m.matricula == buscado)
			existe = true;
	}
	return existe;
}

void mostrar(parchivo medicos)
{
    tmedico m;
    medicos = fopen("medicos.txt", "rb");
    if (medicos == NULL)
        cout << "Archivo Inexistente" << endl;
    else
    {
        while (!feof(medicos))
        {
            fread(&m, sizeof(m), 1, medicos);
            if (!feof(medicos))
            {
                cout << m.matricula << endl;
                cout << m.apynom << endl;
                cout << m.especialidad << endl;
            }
        }
    }
    fclose(medicos);
}
