/*25) Faça uma função que copia um vetor de double para um outro vetor. Esse outro vetor
é alocado dentro da função que faz a cópia. Mostre os dois vetores.*/

#include<stdio.h>
#include <stdlib.h>

void imprime_vet_double(double *vet,int N);
double *copiarvet(double *vet_origem, int N);
double *copiarvet(double *vet_origem, int N){
    double *ponteiro=NULL;
    ponteiro = (double *) calloc(N,sizeof(double));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    for(int i=0;i<N;i++) ponteiro[i]=vet_origem[i];
    return ponteiro;
    
}

void imprime_vet_double(double *vet,int N){
    for(int i=0;i<N;i++) printf("%.1lf ",vet[i]);
    printf("\n");
}

int main(void){
    double vet_origem[5] ={1,2,3,4,5};
    double *vet_destino = copiarvet(vet_origem,5);
    printf("Vetor origem: ");
    imprime_vet_double(vet_origem,5);
    printf("Vetor destino: ");
    imprime_vet_double(vet_destino,5);
    free(vet_destino);
    return 0;
}