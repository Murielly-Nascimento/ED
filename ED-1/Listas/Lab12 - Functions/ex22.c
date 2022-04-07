/*22) Faça uma função para transformar os números de um vetor de inteiros em seu valor
absoluto (use a função abs (math.h))*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void imprime_vet_int(int *vet,int N);
void modulo(int *vet,int N);

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("vet_int[%d] = %d\n",i,vet[i]);
}
void modulo(int *vet,int N){
    for(int i=0;i<N;i++) vet[i] = abs(vet[i]);
}

int main(void){
    int vet[5]={-1,-2,-3,4,5};

    printf("Vetor original\n");
    imprime_vet_int(vet,5);
    modulo(vet,5);
    printf("Vetor modulo\n");
    imprime_vet_int(vet,5);

    return 0;
}