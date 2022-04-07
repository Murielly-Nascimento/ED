/*3) Faça um algoritmo que calcule a média ponderada das notas de 3 provas. A primeira e
a segunda prova têm peso 1 e a terceira tem peso 2. Antes de o usuário entrar com as
notas do aluno ele deve informar a letra inicial do nome do aluno. Ao final, mostrar o a
letra inicial do nome do aluno juntamente com a sua média.*/

#include<stdio.h>

int main(void){
    double nota1=0.0, nota2=0.0, nota3=0.0, media=0.0;
    char nome='\0';

    printf("<< Cálculo da Média >>\n");
    printf("Digite o nome do aluno:");
    scanf("%c",&nome);
    printf("Digite a nota da prova 1:");
    scanf("%lf",&nota1);
    printf("Digite a nota da prova 2:");
    scanf("%lf",&nota2);
    printf("Digite a nota da prova 3:");
    scanf("%lf",&nota3);

    media = (nota1 + nota2 + nota3*2)/4;
    printf("A nota média do aluno %c. é %.0lf\n",nome,media);
    return 0;
}