/*4) Crie uma struct que armazene pontos inteiros (coordenadas x e y – valores inteiros). Crie dinamicamente um
vetor de tamanho n (informado pelo usuário) e indique as coordenadas x e y de cada ponto. Ao final,
mostrar todos os números digitados*/

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

    for(int i=0; i<tamanho; i++){
        printf("Digite as coordenadas do ponto %d:\n",i+1);
        printf("X = ");
        scanf("%d",&coordenadas[i].x);
        printf("Y = ");
        scanf("%d",&coordenadas[i].y);
    } 

    printf("Pontos digitados: ");
    for(int i=0; i<tamanho; i++)
        printf("(%d,%d); ",coordenadas[i].x,coordenadas[i].y);
    printf("\n");
    free(coordenadas);

    return 0;
}