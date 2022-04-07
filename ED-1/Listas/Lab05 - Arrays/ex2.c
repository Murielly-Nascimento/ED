/*2) Refazer o exercício anterior utilizando loop for. Todos os próximos exercícios devem
ser feitos com loops (pense qual o melhor loop: for, while ou do-while)*/

#include<stdio.h>

int main(void){
    int vetor[6]={0};
    
    printf("<< Listando um vetor >>\n");
    for(int i = 0; i < 6 ; i++){
        printf("Entre com o número %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("Os valores lidos são:");
    for(int i = 0; i < 6 ; i++) printf(" %d ",vetor[i]);
    printf("\n");
    return 0;
}