/*16) Faça um programa que leia um vetor de 8 posições e verifique se existem valores
iguais e os escreva a quantidade de vezes que eles aparecem na lista*/

#include<stdio.h>
#include<stdbool.h>

int main(void){
    int vet[8]={0},iguais[8]={0},repet[8]={0},aux=0;
    bool repetido = false;
    
    printf("<< Valores iguais >>\n");
    for(int i=0;i<8;i++){
        printf("Entre com o número %d: ",i+1);
        scanf("%d",&vet[i]);
    }
    
    
    for(int i = 0; i < 8; i++){
        repetido = false;

        for(int j = i+1; j < 8; j++){
        
            if(vet[i] == vet[j] && vet[j]!=0){
                iguais[aux]=vet[j];
                repet[aux]+=1;
                vet[j]=0;
                repetido=true;
            }
        }
        if(repetido) aux++;
    }

    printf("\nValores repetidos:\n");
    for(int i=0;i<aux;i++) printf("%d aparece %d vezes\n",iguais[i],repet[i]+1);
    printf("\n");

    return 0;
}