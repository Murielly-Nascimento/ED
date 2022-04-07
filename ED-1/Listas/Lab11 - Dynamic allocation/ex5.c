/*5) Modifique o programa anterior incluindo quatro ponteiros, que apontarão para os seguintes pontos: mais a
esquerda, mais a direita, mais acima, mais abaixo. Mostre quem são esses pontos utilizando esses ponteiros.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}PONTOS;

int main(void){
    int tamanho = 0;
    printf("Digte o tamanho do vetor: ");
    scanf("%d",&tamanho);

    PONTOS *coordenadas = malloc(tamanho*sizeof(PONTOS));
    PONTOS *norte = malloc(tamanho*sizeof(PONTOS));
    PONTOS *sul = malloc(tamanho*sizeof(PONTOS));
    PONTOS *leste = malloc(tamanho*sizeof(PONTOS));
    PONTOS *oeste = malloc(tamanho*sizeof(PONTOS));

    for(int i=0; i<tamanho; i++){
        printf("Digite as coordenadas do ponto %d:\n",i+1);
        printf("X = ");
        scanf("%d",&coordenadas[i].x);
        printf("Y = ");
        scanf("%d",&coordenadas[i].y);
        norte[i].x = coordenadas[i].x; norte[i].y = coordenadas[i].y + 1;
        sul[i].x = coordenadas[i].x; sul[i].y = coordenadas[i].y - 1;
        leste[i].x = coordenadas[i].x + 1; leste[i].y = coordenadas[i].y;
        oeste[i].x = coordenadas[i].x - 1; oeste[i].y = coordenadas[i].y;
    } 

    printf("\nPontos digitados: ");
    for(int i=0; i<tamanho; i++){
        printf("Ponto %d (%d,%d); \n",i+1,coordenadas[i].x,coordenadas[i].y);
        printf("norte(%d,%d); \n",norte[i].x,norte[i].y);
        printf("sul(%d,%d); \n",sul[i].x,sul[i].y);
        printf("leste(%d,%d); \n",leste[i].x,leste[i].y);
        printf("oeste(%d,%d); \n",oeste[i].x,oeste[i].y);
        printf("\n");
    }
    free(coordenadas);
    free(norte);
    free(sul);
    free(leste);
    free(oeste);

    return 0;
}