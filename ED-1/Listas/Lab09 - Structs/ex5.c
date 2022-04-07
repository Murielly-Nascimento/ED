/*5. Crie uma estrutura representando os alunos de um curso de graduação. A estrutura
deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda
prova, nota da terceira prova, média e número de faltas.

(a) Permita ao usuário entrar com os dados de 3 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral.
(e) Mostre a situação final do aluno. Para ser aprovado o aluno precisa ter nota média final
maior ou igual a 60 e ter presença maior ou igual a 75% (considere um total de 72 aulas). No
caso de reprovação, mostrar o motivo da mesma, isto é, caso o aluno foi reprovado por falta,
mostrar “Reprovado por falta”. Caso tenha sido reprovado por nota, mostrar “Reprovado por
nota”. Se um aluno foi reprovado por falta e por nota, prevalece, como motivo para
reprovação, as faltas. Assim, mostrar a mensagem “Reprovado por falta”.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define STRING 60

struct ALUNO{
    int matricula;
    char nome[STRING];
    double notas[3];
    double media;
    int faltas;
};

int main(void){
    struct ALUNO aluno[3];
    double maiorNota1 = -1, maiorMedia=-1, menorMedia=10000;
    int maiorNotaAux = 0, maiorMediaAux=0, menorMediaAux=0;
    printf("Digite os dados de 3 alunos: \n");
    for(int i=0;i<3;i++){
        printf("Matricula do aluno %d: ",i+1);
        scanf("%d",&aluno[i].matricula);
        printf("Nome do aluno %d: ",i+1);
        setbuf(stdin,NULL);
        fgets(aluno[i].nome,sizeof(aluno[i].nome),stdin);
        aluno[i].nome[strcspn(aluno[i].nome,"\n")]='\0';
        setbuf(stdin,NULL);
        for(int j=0;j<3;j++){
            printf("Digite a nota da prova %d:",j+1);
            scanf("%lf",&aluno[i].notas[j]);
            aluno[i].media += aluno[i].notas[j];
        }
        aluno[i].media = aluno[i].media/3.0;
        printf("Digite o numero de faltas do aluno %d: ",i+1);
        scanf("%d",&aluno[i].faltas);
        if(aluno[i].notas[0]>maiorNota1){
            maiorNota1 = aluno[i].notas[0];
            maiorNotaAux = i;
        }if(aluno[i].media>maiorMedia){
            maiorMedia = aluno[i].media;
            maiorMediaAux = i;
        }if(aluno[i].media<menorMedia){
            menorMedia = aluno[i].media;
            menorMediaAux = i;
        }
        if(aluno[i].media>=60 && aluno[i].faltas<54) printf("%s foi APROVADO\n",aluno[i].nome);
        else if(aluno[i].media<60 && aluno[i].faltas<54) printf("%s reprovado por nota\n",aluno[i].nome);
        else printf("%s reprovado por faltas\n",aluno[i].nome);
    
    }
    return 0;
}
