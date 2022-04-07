#include <stdio.h>
#include "TStack.h"
#include "aluno.h"

int main(void){

    printf("\n<< CRIANDO STACK >>\n");

    TStack *pilha = NULL;
    pilha = stack_create();
    if(pilha == NULL)
        printf("Erro ao alocar pilha!\n");

    printf("\n<< INSERINDO ELEMENTOS NA PILHAS >>\n");
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},{4,"Ricardo",7.5,8.7,6.8  },{1,"Bianca",9.7,6.7,8.4 },{3,"Ana",5.7,6.1,7.4}};
    struct aluno aux;

    stack_push(pilha,a[0]);
    stack_push(pilha,a[1]);
    stack_push(pilha,a[2]);
    stack_push(pilha,a[3]);
    stack_print(pilha);

    printf("\n<< REMOVENDO ELEMENTOS DA LISTA >>\n");
    stack_pop(pilha);
    stack_print(pilha);

    printf("\n<< ÚLTIMO ELEMENTO INSERIDO >>\n");
    stack_top(pilha, &aux);
    printf("Matricula: %d\n",aux.matricula);
    printf("Nome: %s\n",aux.nome);
    printf("Notas: %f %f %f\n",aux.n1,aux.n2,aux.n3);
    printf("-------------------------------\n");

    printf("\n<< QUAL É O ESTADO DA PILHA? >>\n");
    if(stack_full(pilha) == 0) printf("A lista está cheia\n");
    else if(stack_empty(pilha) == 0) printf("A lista está vazia\n");
    else printf("Ainda há espaço na lista\n");

    printf("\n<< LIBERANDO A PILHA >>\n");
    stack_free(pilha);

    return 0;
}