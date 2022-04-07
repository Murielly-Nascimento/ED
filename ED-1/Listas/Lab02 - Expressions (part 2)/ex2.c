/*2) Altere o algoritmo anterior para que, antes de o usuário entrar com as notas do aluno
ele entre com a inicial do nome do aluno. Ao final, mostrar a inicial do nome do aluno
juntamente com a sua média.*/

#include<stdio.h>

int main(void){
    double nota1=0.0, nota2=0.0, media=0.0;
    char nome='\0';

    printf("<< Cálculo da Média >>\n");
    printf("Digite o nome do aluno:");
    scanf("%c",&nome);
    printf("Digite a nota da prova 1:");
    scanf("%lf",&nota1);
    printf("Digite a nota da prova 2:");
    scanf("%lf",&nota2);

    media = (nota1 + nota2)/2;
    printf("A nota média do aluno %c. é %.1lf\n",nome,media);
    return 0;
}