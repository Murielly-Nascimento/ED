/*4) Altere o exercício 2 para que o programa somente aceite números pares. Dica: é
melhor usar loop while para ler os números*/

#include<stdio.h>

int main(void){
    int i=0,vetor[6]={0};
    printf("<< Listando um vetor de números pares>>\n");
    while(i<6){
        printf("Entre com o número %d:",i+1);
        scanf("%d",&vetor[i]);
        if(vetor[i]%2!=0) printf("Erro: Valor inválido\n");
        else i++;
    }
    printf("Os números pares digitados foram:");
    for(int i = 0; i < 6 ; i++) printf(" %d ",vetor[i]);
    printf("\n");
    return 0;
}