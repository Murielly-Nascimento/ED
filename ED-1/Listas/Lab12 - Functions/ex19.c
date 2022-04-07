/*19) Implemente uma função que receba como parâmetro um vetor de n números reais
(VET) de tamanho N e retorne quantos números negativos há a nesse vetor. Use o
seguinte protótipo*/

#include<stdio.h>

int negativos(float *vet, int N);

int negativos(float *vet, int N){
    int neg = 0;
    for(int i=0;i<N;i++){
        if(vet[i]<0) neg++;
    }
    return neg;
}

int main(void){
    float vetori[5]={-11,12,13,14,15};
    int neg = negativos(vetori,5);
    printf("O numero de valores negativos é %d\n",neg);
    return 0;
}