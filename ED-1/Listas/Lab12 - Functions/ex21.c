/*21) Faça uma função para multiplicar um vetor por um escalar (um número). Mostre, no
programa principal, o vetor antes e depois da multiplicação.*/

#include<stdio.h>

void imprime_vet_int(int *vet,int N);
void multiplicar(int *vet,int N,int K);

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("vet_int[%d] = %d\n",i,vet[i]);
}
void multiplicar(int *vet,int N,int K){
    for(int i=0;i<N;i++) vet[i] *= K;
}

int main(void){
    int vet[5]={1,2,3,4,5};
    int K = 5;

    printf("Vetor original\n");
    imprime_vet_int(vet,5);
    multiplicar(vet,5,K);
    printf("Vetor multiplicadoo\n");
    imprime_vet_int(vet,5);

    return 0;
}