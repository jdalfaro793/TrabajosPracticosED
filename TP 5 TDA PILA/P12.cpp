#include <iostream>
using namespace std;


typedef struct tnodo *pnodo;
typedef struct tnodo{
						char letra;
						pnodo sig;
					};

typedef struct tlista{	
						pnodo inicio;
						int letras;
						int simbolos;
					};

typedef pnodo tcontenedor[30];
typedef struct tpila{
						tcontenedor datos;
						int cima;
					};


int main(int argc, char *argv[]) {
	
	return 0;
}

