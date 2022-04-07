/*Crie três funções chamadas imprime_vet_int, imprime_vet_double, imprime_vet_float
que mostra o conteúdo de um vetor de inteiros, double, e float, respectivamente. Use
essas funções sempre que precisar mostrar um vetor.*/

#include<stdio.h>

void imprime_vet_int(int *vet,int N);
void imprime_vet_float(float *vet,int N);
void imprime_vet_double(double *vet,int N);

void imprime_vet_int(int *vet,int N){
    for(int i=0;i<N;i++) printf("vet_int[%d] = %d\n",i,vet[i]);
}
void imprime_vet_float(float *vet,int N){
    for(int i=0;i<N;i++) printf("vet_float[%d] = %.1f\n",i,vet[i]);
}
void imprime_vet_double(double *vet,int N){
    for(int i=0;i<N;i++) printf("vet_double[%d] = %.1lf\n",i,vet[i]);
}

int main(void){
    int vet[5]={1,2,3,4,5};
    float vetor[5]={6,7,8,9,10};
    double vetori[5]={11,12,13,14,15};

    imprime_vet_int(vet,5);
    printf("\n");
    imprime_vet_float(vetor,5);
    printf("\n");
    imprime_vet_double(vetori,5);

    return 0;
}