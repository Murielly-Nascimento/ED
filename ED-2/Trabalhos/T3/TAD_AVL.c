#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "TAD_AVL.h"

#define SIZE 50

// CRIA ARVORE
ArvAVL *cria_ArvAVL()
{
    ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));

    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

// LIBERA NO
void libera_NO(struct NO *no)
{
    if (no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

// LIBERA ARVORE
void libera_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    libera_NO(*raiz); // libera cada nó
    free(raiz);       // libera a raiz
}

// ALTURA DO NO
int altura_NO(struct NO *no)
{
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

// FATOR DE BALANCEAMENTO
int fatorBalanceamento_NO(struct NO *no)
{
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

// SE VAZIA
int estaVazia_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 1;
    if (*raiz == NULL)
        return 1;
    return 0;
}

// TOTAL NO
int totalNO_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

// ALTURA DA ARVORE AVL
int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

// EM ORDEM
void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    if (*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %s: H(%d) fb(%d)\n", (*raiz)->palavra, altura_NO(*raiz), fatorBalanceamento_NO(*raiz));
        for (int i = 0; i < (*raiz)->pos; i++)
            printf("%d ", (*raiz)->linha[i]);
        printf("\n");
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

// CONSULTA
int consulta_ArvAVL(ArvAVL *raiz, char *valor)
{
    if (raiz == NULL)
        return 0;
    struct NO *atual = *raiz;
    while (atual != NULL)
    {
        if (strcmp(valor, atual->palavra) == 0)
        {
            return 1;
        }
        if (strcmp(valor, atual->palavra) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//=================================
int maior(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void RotacaoDireita(ArvAVL *A)
{ // LL
    // printf("\nRotacao Direita");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
    *A = B;
}

void RotacaoEsquerda(ArvAVL *A)
{ // RR
    // printf("\nRotacao Esquerda");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;
    (*A) = B;
}

void RotacaoDuplaDireita(ArvAVL *A)
{ // LR
    // printf("\nRotacao Dupla Direita");
    RotacaoEsquerda(&(*A)->esq);
    RotacaoDireita(A);
}

void RotacaoDuplaEsquerda(ArvAVL *A)
{ // RL
    // printf("\nRotacao Dupla Esquerda");
    RotacaoDireita(&(*A)->dir);
    RotacaoEsquerda(A);
}

int insere_ArvAVL(ArvAVL *raiz, char *valor, int linha)
{
    int r;
    if (*raiz == NULL)
    { //árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO *)malloc(sizeof(struct NO));
        if (novo == NULL)
            return 0;

        char pos = linha + '0';

        strcpy(novo->palavra, valor);
        novo->linha[novo->pos] = linha;
        novo->pos++;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;

    if (strcmp(valor, atual->palavra) < 0)
    {
        r = insere_ArvAVL(&(atual->esq), valor, linha);
        if (r == 1)
        {
            if (fatorBalanceamento_NO(atual) >= 2)
            {

                if (strcmp(valor, (*raiz)->esq->palavra) < 0)
                {
                    RotacaoDireita(raiz);
                }
                else
                {
                    RotacaoDuplaDireita(raiz);
                }
            }
        }
    }
    else
    {

        if (strcmp(valor, atual->palavra) > 0)
        {
            r = insere_ArvAVL(&(atual->dir), valor, linha);
            if (r == 1)
            {
                if (fatorBalanceamento_NO(atual) >= 2)
                {

                    if (strcmp((*raiz)->dir->palavra, valor) < 0)
                    {
                        RotacaoEsquerda(raiz);
                    }
                    else
                    {
                        RotacaoDuplaEsquerda(raiz);
                    }
                }
            }
        }
        else
        {
            atual->linha[atual->pos] = linha;
            atual->pos++;
            // printf("Valor duplicado!!\n");
            return 0;
        }
    }
    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

    return r;
}

struct NO *procuraMenor(struct NO *raiz)
{
    struct NO *atual, *prox;
    if (estaVazia_ArvAVL(&raiz))
        return NULL;
    atual = raiz;
    prox = raiz->esq;
    while (prox != NULL)
    {
        atual = prox;
        prox = prox->esq;
    }
    return atual;
}