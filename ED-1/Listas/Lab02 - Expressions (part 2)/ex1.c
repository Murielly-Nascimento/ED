/*1) Faça um algoritmo que calcula a média das notas de 2 provas.*/

#include<stdio.h>

int main(void){
    double nota1=0.0, nota2=0.0, media=0.0;

    printf("<< Cálculo da Média >>\n");
    printf("Digite a nota da prova 1:");
    scanf("%lf",&nota1);
    printf("Digite a nota da prova 2:");
    scanf("%lf",&nota2);

    media = (nota1 + nota2)/2;
    printf("A nota média é %.0lf\n",media);
    return 0;
}