/*10) Faça uma função chamada imprime_ponto, que recebe uma struct do tipo ponto e
mostra na tela o ponto no seguinte formato (ponto.x, ponto.y)*/

#include<stdio.h>

struct ponto{
    int x;
    int y;
};

void imprimePonto(struct ponto P){
    printf("(%d,%d)\n",P.x,P.y);
}

int main(void){
    struct ponto P;
    printf("Digite as coordenadas de um ponto: ");
    scanf("%d",&P.x);
    scanf("%d",&P.y);
    imprimePonto(P);

    return 0;
}