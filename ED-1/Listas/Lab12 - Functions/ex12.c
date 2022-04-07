/*12) Crie um procedimento idêntico ao exercício anterior, mas que agora retorne void e
coloque o resultado da soma no terceiro argumento da função.*/

#include<stdio.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
void soma_ponto(struct ponto * P1, struct ponto * P2,struct ponto * P3);

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

void soma_ponto(struct ponto * P1, struct ponto * P2,struct ponto * P3){
    P3->x = P1->x + P2->x;
    P3->y = P1->y + P2->y;
}

int main(void){
    struct ponto P1,P2,P3;
    printf("Digite as coordenadas do ponto P1: ");
    scanf("%d",&P1.x);
    scanf("%d",&P1.y);
    printf("Digite as coordenadas do ponto P2: ");
    scanf("%d",&P2.x);
    scanf("%d",&P2.y);
    soma_ponto(&P1,&P2,&P3);
    printf("A soma de ");
    imprimePonto(P1);
    printf(" com ");
    imprimePonto(P2);
    printf(" é ");
    imprimePonto(P3);
    printf("\n");

    return 0;
}