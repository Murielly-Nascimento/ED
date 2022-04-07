/*9) Escreva um programa que leia as coordenadas x e y de pontos no R2 e calcule sua
distância da origem (0,0). Obs: faça #include <math.h> e use a função sqrt() para
calcular a raiz de um número
*/

#include<stdio.h>
#include<math.h>

int main(void){
    int x = 0, y = 0;
    printf("<< Distância >>\n");
    printf("Entre com a coordenada x:");
    scanf("%d",&x);
    printf("Entre com a coordenada y:");
    scanf("%d",&y);

    double distancia = 0.0;
    distancia = sqrt(pow(x,2) + pow(y,2));
    printf("A distância entre os pontos (%d,%d) e (0,0) eh %.1lf\n",x,y,distancia);
    return 0;
}
