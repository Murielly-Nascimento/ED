/*11) Faca uma função que some dois pontos e retorne o resultado da soma. Mostre os 3
pontos usando a função imprime_ponto.*/

#include<stdio.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
struct ponto soma_ponto(struct ponto P1, struct ponto P2);

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

struct ponto soma_ponto(struct ponto P1, struct ponto P2){
    struct ponto P3;
    P3.x = P1.x + P2.x;
    P3.y = P1.y + P2.y;
    return P3;
}

int main(void){
    struct ponto P1,P2,P3;
    printf("Digite as coordenadas do ponto P1: ");
    scanf("%d",&P1.x);
    scanf("%d",&P1.y);
    printf("Digite as coordenadas do ponto P2: ");
    scanf("%d",&P2.x);
    scanf("%d",&P2.y);
    P3 = soma_ponto(P1,P2);
    printf("A soma de ");
    imprimePonto(P1);
    printf(" com ");
    imprimePonto(P2);
    printf(" é ");
    imprimePonto(P3);
    printf("\n");

    return 0;
}