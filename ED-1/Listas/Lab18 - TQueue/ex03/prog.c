#include <stdio.h>
#include "TSeqQueue.h"
#include "aluno.h"
#include "TSeqQueue.c"

int main(void){

    printf("\n<< CRIANDO FILA >>\n");

    TSeqQueue *fila = NULL;
    printf("Digite um tamanho: ");
    int tamanho = 0;
    scanf("%d",&tamanho);
    fila = queue_create(tamanho);
    if(fila == NULL)
        printf("Erro ao alocar fila!\n");

    printf("\n<< INSERINDO ELEMENTOS NA FILA >>\n");
    struct aluno a[4] = {{1,"Andre",9.5,7.8,8.5},{2,"Ricardo",7.5,8.7,6.8  },{3,"Bianca",9.7,6.7,8.4 },{4,"Ana",5.7,6.1,7.4}};
    struct aluno aux;

    queue_push(fila,a[0]);
    queue_push(fila,a[1]);
    queue_push(fila,a[2]);
    queue_push(fila,a[3]);
    queue_print(fila);

    printf("\n<< REMOVENDO ELEMENTOS DA FILA >>\n");
    queue_pop(fila);
    queue_print(fila);
    
    printf("\n<< ELEMENTO NO TOPO DA FILA >>\n");
    queue_top(fila, &aux);
    printf("Matricula: %d\n",aux.matricula);
    printf("Nome: %s\n",aux.nome);
    printf("Notas: %f %f %f\n",aux.n1,aux.n2,aux.n3);
    printf("-------------------------------\n");

    printf("\n<< COMPACTA LISTA >>\n");
    compact_list(fila);
    queue_print(fila);
    
    printf("\n<< LIBERANDO A FILA >>\n");
    queue_free(fila);

    return 0;
}