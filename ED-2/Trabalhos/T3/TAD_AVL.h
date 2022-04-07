#define TAM 50

struct NO
{
    char palavra[TAM];
    int linha[TAM];
    int pos;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO *ArvAVL;

ArvAVL *cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, char *valor, int linha);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, char *valor);
void emOrdem_ArvAVL(ArvAVL *raiz);