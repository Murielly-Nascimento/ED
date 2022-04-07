/*7) Elabore um algoritmo para normalizar as notas de uma turma de 5 alunos. A maior
nota deve virar 100.*/

#include<stdio.h>

int main(void){
    double vet[5]={0.0};
    
    printf("<<Normalizando as notas>>\n");
    for(int i=0;i<5;i++){
        printf("Entre com a nota do aluno %d: ",i+1);
        scanf("%lf",&vet[i]);
    }
    printf("Notas normalizadas\n");
    for(int i=0;i<5;i++) printf("A nota do aluno %d é %.0lf\n",i+1,vet[i]*2);

    return 0;
}