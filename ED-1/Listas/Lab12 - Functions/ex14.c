/*14) Faça um procedimento que multiplique o valor de um ponto por uma constante e
altere o valor do ponto. Deve ser usada passagem por referência e retorno void*/

#include<stdio.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
void mult_ponto(struct ponto * P1, int N);

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

void mult_ponto(struct ponto * P1, int N){
    P1->x *=N;
    P1->y *=N;
}

int main(void){
    struct ponto P1;
    int N=0;
    printf("Digite as coordenadas do ponto P1: ");
    scanf("%d",&P1.x);
    scanf("%d",&P1.y);
    printf("Digite a constante: ");
    scanf("%d",&N);
    printf("Resultado: ");
    imprimePonto(P1);
    mult_ponto(&P1,N);
    printf(" * %d = ",N);
    imprimePonto(P1);
    printf("\n");

    return 0;
}