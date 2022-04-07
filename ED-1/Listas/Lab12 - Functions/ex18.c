/*18) Crie um procedimento que recebe um vetor de double como entrada e devolve o
maior e o menor elemento do vetor. Mostre no programa principal o vetor, o maior e
o menor elemento*/

#include<stdio.h>

void imprime_vet_double(double *vet,int N);
void MaiorMenor(double *vet,int N,double *maior,double *menor);

void imprime_vet_double(double *vet,int N){
    for(int i=0;i<N;i++) printf("vet_double[%d] = %.1lf\n",i,vet[i]);
}
void MaiorMenor(double *vet,int N,double *maior,double *menor){
    for(int i=0;i<N;i++){
        if(vet[i]<*menor) *menor =vet[i];
        if(vet[i]>*maior) *maior =vet[i];
    }
}

int main(void){
    double vetori[5]={11,12,13,14,15};
    double maior = vetori[0];
    double menor = vetori[0];
    MaiorMenor(vetori,5,&maior,&menor);
    imprime_vet_double(vetori,5);
    printf("O maior elemento = %.2lf\nO menor elemento = %.2lf\n",maior,menor);
    return 0;
}