/*9) Faça um programa que calcula a média das notas dos alunos de uma turma. Note que
uma turma pode ter no máximo 100 alunos (mostrar uma msg de erro caso o número
escolhido seja maior que 100). Peça para o usuário entrar com o número de alunos e
ao final mostre a nota de todos os alunos.*/

#include<stdio.h>

int main(void){
    int notas[100]={0},n=0;
    printf("<< Média de n alunos. Máximo 100 alunos >>\n");
    printf("Entre com o número de alunos: ");
    scanf("%d",&n);

    if(n>100) printf("Erro! O número máximo de alunos permitido é 100.\n");
    else{
        double media=0.0;
        for(int i=0;i<n;i++){
            printf("Digite a nota do aluno %d: ",i+1);
            scanf("%d",&notas[i]);
            media+=notas[i];
        }
        printf("Relatório de Notas\n");
        for(int i=0;i<n;i++) printf("A nota do aluno %d é: %d\n",i,notas[i]);
        printf("A média da turma é: %.1lf\n",media/n);
    }
    return 0;
}