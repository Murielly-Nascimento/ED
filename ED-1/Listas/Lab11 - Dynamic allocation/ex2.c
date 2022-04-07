/*2) Crie um programa que:
(a) Aloque dinamicamente um array de 5 números inteiros,
(b) Peça para o usuário digitar os 5 números no espaço alocado,
(c) Mostre na tela os 5 números,
(d) Libere a memoria alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tamanho = 5;
    int *vetor = malloc(tamanho*sizeof(int));

    for(int i=0;i<5;i++){
        printf("Digite o valor %d: ",i+1);
        scanf("%d",&vetor[i]);
    }
    for(int i=0;i<5;i++)
        printf("vetor[%d]: %d\n",i,vetor[i]);
    
    free(vetor);

    return 0;
}