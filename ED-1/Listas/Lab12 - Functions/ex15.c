/*15) Faça um procedimento chamado inc_dir, que faz o ponto andar uma unidade para
leste, oeste, norte, sul (passar como referência e retorno void)*/

#include<stdio.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
void inc_dir(struct ponto *A, char direcao);

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

void inc_dir(struct ponto *A, char direcao){
    switch(direcao){
        case 'l': A->x+=1;
        break;
        case 'o': A->x-=1;
        break;
        case 'n': A->y+=1;
        break;
        case 's': A->y-=1;
        break;
        default:
        break;
    }
}   

int main(void){
    struct ponto A;
    printf("<< CARTOGRAFIA >>\n");
    printf("Digite as coordenadas de um ponto A: ");
    scanf("%d",&A.x);
    scanf("%d",&A.y);
    printf("Digite a direção (oeste,sul,leste,norte) para qual o ponto vai: ");
    char direcao='\0';
    setbuf(stdin,NULL);
    scanf("%c",&direcao);
    imprimePonto(A);
    inc_dir(&A,direcao);
    printf("=>");
    imprimePonto(A);
    printf("\n");

    return 0;
}