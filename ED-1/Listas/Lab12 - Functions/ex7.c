/*7) Faça um procedimento “Troque”, que recebe duas variáveis reais A e B e troca o valor
delas (i.e., A recebe o valor de B e B recebe o valor de A). Mostre no programa
principal o resultado da troca*/

#include<stdio.h>

void Troque(int *A,int *B);

void Troque(int *A,int *B){
    int aux= *A;
    *A = *B;
    *B = aux;
}

int main(void){
    int A = 0,B = 0;
    printf("<< TROCA >>\n");
    printf("Digite o valor de A: ");
    scanf("%d",&A);
    printf("Digite o valor de B: ");
    scanf("%d",&B);
    Troque(&A,&B);
    printf("O valor de A = %d\nO valor de B = %d\n",A,B);

    return 0;
}