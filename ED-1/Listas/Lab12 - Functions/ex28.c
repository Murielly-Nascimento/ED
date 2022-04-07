/*28) Tente fazer uma função que copia um vetor de double para um outro vetor. Esse outro
vetor é alocado dentro da função que faz a cópia. Mostre vet_destino no programa
principal*/

/*RESPOSTA: A função não funiona porque o vetor alocado dinamicamente na funcao copiar_vet
está definido no escopo local da função sem qualquer link com a função main. Para solucinar
esse problema a função copiarvet deve retornar o ponteiro para o vetor_destino
*/

#include<stdio.h>
#include <stdlib.h>

void imprime_vet_double(double *vet,int N);
void copiarvet(double *vet_origem,double *vet_destino, int N);
void copiarvet(double *vet_origem,double *vet_destino, int N){
    double *ponteiro=NULL;
    ponteiro = (double *) calloc(N,sizeof(double));
    if(ponteiro==NULL){
        printf("Erro: Memoria Insuficiente!\n");
    }
    for(int i=0;i<N;i++) ponteiro[i]=vet_origem[i];
    for(int i=0;i<N;i++) vet_destino[i]=ponteiro[i];

}

void imprime_vet_double(double *vet,int N){
    for(int i=0;i<N;i++) printf("%.1lf ",vet[i]);
    printf("\n");
}

int main(void){
    double vet_origem[5] ={1,2,3,4,5};
    double vet_destino[5]={0};
    copiarvet(vet_origem,vet_destino,5);
    printf("Vetor origem: ");
    printf("Vetor destino: ");
    imprime_vet_double(vet_destino,5);
    free(vet_destino);
    return 0;
}