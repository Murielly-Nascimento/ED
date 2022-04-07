struct url{
  char chave[50];
  char url[100];
  struct url *prox;
};

typedef struct url URL;

struct tabelaHs {
	int tamanho;
	URL **tab;	
};

typedef struct tabelaHs TabelaHs;

TabelaHs *criar (int tam);
void inserirTermoTh(TabelaHs *tabTermos, char *ptChave, char *enValor);
char *buscarTermoTh(TabelaHs *hashtable, char *key);
int *removerTermoTh(TabelaHs *hashtable, char *key);
void percursoTh(TabelaHs *tabTermos);
void liberaTh(TabelaHs *tabTermos);
