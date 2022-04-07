/*27) Crie uma função para alocar dinamicamente um vetor de n pontos e inicialize esses
pontos como (0,0).*/

#include<stdio.h>
#include <stdlib.h>

struct pontos{
    int x;
    int y;
};

void imprime_vet_pontos(struct pontos *vet,int N);
void *alocaPontos(int N);

void *alocaPontos(int N){
    struct pontos *ponteiro=NULL;
    ponteiro = (struct pontos *) calloc(N,sizeof(struct pontos));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    return ponteiro;
}
void imprime_vet_pontos(struct pontos *vet,int N){
    for(int i=0;i<N;i++) printf("(%d,%d)",vet[i].x,vet[i].y);
    printf("\n");
}

int main(void){
    int N=0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);
    struct pontos *ponteiro = alocaPontos(N);
    imprime_vet_pontos(ponteiro,N);
    free(ponteiro);
    return 0;
}