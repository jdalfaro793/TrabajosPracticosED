#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

typedef FILE *parchivo;


void cargar(parchivo f);
void mostrar(parchivo f);
float aleatorio();

main()
{
    parchivo fp;
    srand(time(NULL));
    cargar(fp);
    mostrar(fp);
    system ("pause");
}


void cargar(parchivo f)
{
    char letra;
    int i;
    float azar;
    f = fopen("fichero.dat", "wb+");
    for (i = 0; i < 30; i++)
    {
        azar = aleatorio();
        if (azar < 0.33)
            letra = 65 + rand() % 26;
        else if (azar < 0.66)
            letra = 97 + rand() % 26;
        else
            letra = 48 + rand() % 10;
        fwrite(&letra, sizeof(letra), 1, f);
    }

    fclose (f);
}


void mostrar(parchivo f)
{
    char letra;
    f = fopen("fichero.dat", "rb");
    while (!feof(f))
    {
        fread(&letra, sizeof(letra), 1, f);
        if (!feof(f))
            cout << letra << " ";
    }
    cout << endl;
    fclose(f);
}


float aleatorio()
{
    return rand() * 1.0 / RAND_MAX;
}
