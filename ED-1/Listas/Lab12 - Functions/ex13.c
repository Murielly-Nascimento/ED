/*13) Faça uma função que calcule a área do retângulo definido por dois pontos.*/

#include<stdio.h>
#include<stdlib.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P);
double calc_area(struct ponto A, struct ponto B);

double calc_area(struct ponto A, struct ponto B){
    int comp=0,h=0;
    comp = abs(A.x - B.x);
    h = abs(A.y - B.y);

    return comp*h;
}

void imprimePonto(struct ponto P){
    printf("(%d,%d)",P.x,P.y);
}

int main(void){
    struct ponto P1,P2;
    printf("Digite as coordenadas do ponto P1: ");
    scanf("%d",&P1.x);
    scanf("%d",&P1.y);
    printf("Digite as coordenadas do ponto P2: ");
    scanf("%d",&P2.x);
    scanf("%d",&P2.y);
    printf("A área do retângulo definido por ");
    imprimePonto(P1);
    printf(" e ");
    imprimePonto(P2);
    printf(" é %.0lf\n",calc_area(P1,P2));


    return 0;
}