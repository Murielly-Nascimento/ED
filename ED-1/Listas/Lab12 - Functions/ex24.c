/*24)Crie uma função aloca_inteiro, que faz a alocação de um vetor inteiro de tamanho n e
que inicialize os elementos desse vetor com o valor zero. Retorne o ponteiro para o
vetor alocado. Imprima no programa principal o vetor alocado.*/

#include<stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet,int N);
int *aloca_inteiro(int N);

int *aloca_inteiro(int N){
    int *ponteiro=NULL;
    ponteiro = (int *) calloc(N,sizeof(int));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    return ponteiro;
}

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("%d ",vet[i]);
    printf("\n");
}

int main(void){
    int N=0;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d",&N);
    int *ponteiro = aloca_inteiro(N);
    imprime_vet_int(ponteiro,N);
    free(ponteiro);
    return 0;
}