/*14) Faça um programa que armazene informações sobre os alunos de uma universidade. O
número máximo de alunos que o sistema pode cadastrar é 10000. Os dados a serem
armazenados são: número de matricula (inteiro); classe social (A, B, C, D ou E); CRA
(real). Ao iniciar o programa, informe quantos usuários serão cadastrados. Depois de
realizado o cadastro, mostre todos os dados lidos. A saída do programa deve ser como
o exemplo abaixo.*/

#include<stdio.h>

int main(void){
    int alunos=0,numero[10000]={0};
    char classe[10000]={'\0'};
    double CRA[10000]={0.0};

    printf("<< Universidade X >>\n");
    printf("Quantos alunos serão cadastrados:");
    scanf("%d",&alunos);

    for(int i=0;i<alunos;i++){
        printf("\n\nEntre com o número do aluno: ");
        scanf("%d",&numero[i]);
        printf("Entre com a classe social do aluno %d: ",numero[i]);
        setbuf(stdin,NULL);
        scanf("%c",&classe[i]);
        getchar();
        printf("Entre com o CRA do aluno %d: ",numero[i]);
        scanf("%lf",&CRA[i]);
    }

    printf("\n\n==== Alunos Cadastrados ====\n");
    for(int i=0;i<alunos;i++){
        printf("Numero: %d Classe Social: %c CRA: %.2lf\n",numero[i],classe[i],CRA[i]);
    }
    
    
    return 0;
}