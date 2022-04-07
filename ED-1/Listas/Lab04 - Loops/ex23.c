/*23) Calcule o número neperiano usando uma série (ver abaixo). Peça para o usuário entrar com o
número de termos que serão somados (note que, quanto maior o número, a resposta estará mais
próxima do valor e)*/

#include<stdio.h>

int main(void){
    int termos=0;
    long double nep=1,fat=1;
    printf("<< Número neperiano >>\n");
    printf("Entre com o número de termos: ");
    scanf("%d",&termos);

    for(int i=1;i<=termos;i++){
        for(int j=1;j<=i;j++){
            fat*=j;
        }
        nep+=1/fat;
        fat=1;
    }
    printf("e ~%.14Lf\n",nep);
    return 0;
}