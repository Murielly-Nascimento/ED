/*3) Faça um programa que leia n inteiros (definidos pelo usuário) armazenando-os em uma memória alocada
dinamicamente. Em seguida, mostre quantos dos n números são pares e quantos são ímpares.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("Digite o tamanho do vetor: ");
    int tamanho = 0;
    scanf("%d",&tamanho);

    int *vetor = malloc(tamanho*sizeof(int));
    int par = 0, impar = 0; 

    for(int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ",i+1);
        scanf("%d",&vetor[i]);
        if(vetor[i] % 2 == 0) par++;
        else impar++;
    }
    printf("%d números são pares e %d são ímpares.\n",par,impar);
    free(vetor);
    return 0;
}