/*4) Altere o algoritmo anterior para permitir que o usuário entre com os pesos da prova.*/

#include<stdio.h>

int main(void){
    double nota1=0.0, nota2=0.0, nota3=0.0, media=0.0;
    int peso1=0, peso2=0, peso3=0;
    char nome='\0';

    printf("<< Cálculo da Média >>\n");
    printf("Digite a inicial do nome do aluno:");
    scanf("%c",&nome);
    printf("Digite a nota da prova 1:");
    scanf("%lf",&nota1);
    printf("Digite a nota da prova 2:");
    scanf("%lf",&nota2);
    printf("Digite a nota da prova 3:");
    scanf("%lf",&nota3);
    printf("Digite o peso da prova 1:");
    scanf("%d",&peso1);
    printf("Digite o peso da prova 2:");
    scanf("%d",&peso2);
    printf("Digite o peso da prova 3:");
    scanf("%d",&peso3);

    media = (nota1*peso1 + nota2*peso2 + nota3*peso3)/(peso1+peso2+peso3);
    printf("A nota média do aluno %c. é %.2lf\n",nome,media);
    return 0;
}