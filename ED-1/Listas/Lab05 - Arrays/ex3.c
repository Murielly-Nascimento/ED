/*3) Faça um algoritmo em que o usuário digite 6 números e o algoritmo mostra na tela os
6 números digitados na ordem inversa*/

#include<stdio.h>

int main(void){
    int vetor[6]={0};
    
    printf("<< Listando um vetor em ordem Inversa >>\n");
    for(int i = 0; i < 6 ; i++){
        printf("Entre com o número %d:",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("A ordem inversa dos números é:");
    for(int i = 5; i >= 0 ; i--) printf(" %d ",vetor[i]);
    printf("\n");
    return 0;
}