/*16) Crie um procedimento para andar na diagonal (sudeste, sudoeste, nordeste, noroeste).
Use obrigatoriamente as funções do exercício anterior.*/

#include<stdio.h>
#include<string.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
void inc_dir(struct ponto *A, char *direcao,int N);

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

void inc_dir(struct ponto *A, char *direcao,int N){
    char dir[N];
    for(int i=0;i<N;i++){
        dir[i] = direcao[i];
    }
    if(strcmp(dir,"sudeste")==0){
        A->x+=1;
        A->y-=1;
    }else if(strcmp(dir,"sudoeste")==0){
        A->x-=1;
        A->y-=1;
    }else if(strcmp(dir,"nordeste")==0){
        A->x+=1;
        A->y+=1;
    }else if(strcmp(dir,"noroeste")==0){
        A->x-=1;
        A->y+=1;
    }
}   

int main(void){
    struct ponto A;
    char direcao[20]={'\0'};

    printf("<< CARTOGRAFIA >>\n");
    printf("Digite as coordenadas de um ponto A: ");
    scanf("%d",&A.x);
    scanf("%d",&A.y);

    printf("Digite a direção (oeste,sul,leste,norte...) para qual o ponto vai: ");
    setbuf(stdin,NULL);
    fgets(direcao,20,stdin);
    direcao[strcspn(direcao, "\n")] = '\0';

    imprimePonto(A);
    inc_dir(&A,direcao,20);
    printf("=>");
    imprimePonto(A);
    printf("\n");

    return 0;
}