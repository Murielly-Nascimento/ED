/*20) Faça uma função para copiar um vetor inteiro para outro vetor. Ambos vetores devem
ter o mesmo tamanho. Mostre no programa principal os dois vetores.*/

#include<stdio.h>

void imprime_vet_int(int *vet,int N);
void copiar(int *vet,int *vet2,int N);

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("vet_int[%d] = %d\n",i,vet[i]);
}
void copiar(int *vet,int *vet2,int N){
    for(int i=0;i<N;i++) vet2[i] = vet[i];
}

int main(void){
    int vet[5]={1,2,3,4,5};
    int vet2[5]={0};

    copiar(vet,vet2,5);
    printf("Vetor original\n");
    imprime_vet_int(vet,5);
    printf("Vetor copiado\n");
    imprime_vet_int(vet2,5);

    return 0;
}