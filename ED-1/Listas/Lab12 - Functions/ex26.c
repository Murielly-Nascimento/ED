/*26) Faça a função to_double, que recebe um vetor de inteiro e retorna um vetor com o
mesmo conteúdo, mas convertido para double*/

#include<stdio.h>
#include <stdlib.h>

void imprime_vet_double(double *vet,int N);
double *to_double(int *vet_origem, int N);

double *to_double(int *vet_origem, int N){
    
    double *ponteiro=NULL;
    ponteiro = (double *) calloc(N,sizeof(double));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    
    for(int i=0;i<N;i++) ponteiro[i]=vet_origem[i];
    return ponteiro;
    
}

void imprime_vet_double(double *vet,int N){
    for(int i=0;i<N;i++) printf("%.1lf  ",vet[i]);
    printf("\n");
}

int main(void){
    int vet_int[5] ={1,2,3,4,5};
    double *vet_double = to_double(vet_int,5);
    printf("Vetor double: ");
    imprime_vet_double(vet_double,5);
    free(vet_double);
    return 0;
}