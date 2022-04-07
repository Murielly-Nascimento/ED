//TAD MATRIZ

typedef struct MATRIZ MATRIZ;

MATRIZ *cria(int linhas, int colunas);
int libera(MATRIZ *matriz);
int insere(MATRIZ *matriz, int i, int j, double val);
int acessa(MATRIZ *matriz, int i, int j, double* val);
int preenche(MATRIZ *matriz,int maximo, int minimo);
int soma(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado);
int multiplica(MATRIZ *matrizA, MATRIZ *matrizB, MATRIZ *matrizResultado);
int multiplica_por_K(MATRIZ *matrizA, int K, MATRIZ *matrizResultado);
int traco(MATRIZ *matrizA, double *resultado);
int soma_das_linhas(MATRIZ *matrizA, double *linhas);
int soma_das_colunas(MATRIZ *matrizA, double *colunas);
void imprime(MATRIZ *matriz);