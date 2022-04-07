/*
4) Ler quatro notas e mostrar as notas e a média aritmética obtida.
*/

#include<stdio.h>

int main(void){

    printf("<< Média aritmética>>\n");
    int A=0,B=0,C=0,D=0;
    printf("Digite a 1a nota:");
    scanf("%d",&A);
    printf("Digite a 2a nota:");
    scanf("%d",&B);
    printf("Digite a 3a nota:");
    scanf("%d",&C);
    printf("Digite a 4a nota:");
    scanf("%d",&D);

    printf("===Notas==\n");
    printf("Nota 1: %d\nNota 2: %d\nNota 3: %d\nNota 4: %d\n",A,B,C,D);
    double media=0.0;
    media=(A+B+C+D)/4;
    printf("Média: %.0lf\n",media);

    return 0;
}
