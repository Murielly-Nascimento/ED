/*6) Altere o exercício anterior para mostrar o índice do vetor associado ao maior número
e ao menor número*/

#include<stdio.h>

int main(void){
    int vet[5]={0},maior=-1,j=0,menor=100000,k=0;
    double media=0.0;
    
    printf("<< 5 valores>>\n");
    for(int i=0;i<5;i++){
        printf("Entre com o número %d: ",i+1);
        scanf("%d",&vet[i]);
        if(vet[i]>maior){
            maior = vet[i];
            j=i;
        } 
        if(vet[i]<menor){
            menor = vet[i];
            k=i;
        } 
        media += vet[i];
    }    
    printf("Os números digitados são: ");
    for(int i=0;i<5;i++) printf("%d ",vet[i]);
    printf("\nO maior valor é %d, localizado na posição %d do vetor\n",maior,j);
    printf("O menor valor é %d, localizado na posição %d do vetor\n",menor,k);
    printf("A média é: %.1lf\n",media/5);

    return 0;
}