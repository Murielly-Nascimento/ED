/*13) Leia um vetor de 5 posições e atribua valor 0 para todos os elementos que possuírem
valores negativos. Mostre o vetor final.*/

#include<stdio.h>

int main(void){
    int vetor[5]={0};
    printf("<< Zerando negativos >>\n");
    for(int i=0;i<5;i++){
        printf("Entre com o número %d: ",i+1);
        scanf("%d",&vetor[i]);
        if(vetor[i]<0) vetor[i]=0;
    }
    printf("Zerando os negativos, obtém-se: ");
    for(int i=0;i<5;i++) printf("%d ",vetor[i]);
    printf("\n");
    return 0;
}