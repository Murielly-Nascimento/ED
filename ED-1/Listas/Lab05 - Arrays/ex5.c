/*5) Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores lidos
juntamente com o maior, o menor e a média dos valores*/

#include<stdio.h>

int main(void){
    int vet[5]={0},maior=-1,menor=100000;
    double media=0.0;
    
    printf("<< 5 valores>>\n");
    for(int i=0;i<5;i++){
        printf("Entre com o número %d: ",i+1);
        scanf("%d",&vet[i]);
        if(vet[i]>maior) maior = vet[i];
        if(vet[i]<menor) menor = vet[i];
        media += vet[i];
    }    
    printf("Os números digitados são: ");
    for(int i=0;i<5;i++) printf("%d ",vet[i]);
    printf("\nO maior valor é: %d\n",maior);
    printf("O menor valor é: %d\n",menor);
    printf("A média é: %.1lf\n",media/5);

    return 0;
}