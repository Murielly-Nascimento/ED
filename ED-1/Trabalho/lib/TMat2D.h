//TAD MATRIZ

#ifndef _TMat2Dh_
#define _TMat2Dh_

typedef struct MATRIZ MATRIZ;

struct MATRIZ{
  int nlinhas; // número de linhas
  int ncolunas; // número de colunas
  int* dados; // ponteiro para os dados da matriz
};

MATRIZ *cria(int linhas, int colunas);

int libera(MATRIZ *matriz);
int insere(MATRIZ *matriz, int i, int j, int val);
int acessa(MATRIZ *matriz, int i, int j, int* val);
int preenche(MATRIZ *matriz,int maximo, int minimo);
int soma(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado);
int multiplica(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado);
int multiplica_por_K(MATRIZ *matrizA, int K, MATRIZ *matrizResultado);
int traco(MATRIZ *matrizA, int *resultado);
int soma_das_linhas(MATRIZ *matrizA, int *linhas);
int soma_das_colunas(MATRIZ *matrizA, int *colunas);
void imprime(MATRIZ *matriz);

#endif

