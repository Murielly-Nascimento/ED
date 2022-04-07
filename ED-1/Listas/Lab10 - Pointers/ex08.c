#include<stdio.h>

int main(void){
    
    int num=0;
    void *pNum=NULL;

    double decimal=0.0;
    void *pDecimal=NULL;
    
    pNum = &num;
    pDecimal = &decimal;
    
    printf("Digite um numero natural e um numero racional: ");
    scanf("%d",(int *)pNum);
    scanf("%lf",(double *)pDecimal);

    printf("Os numeros lidos são: %d %.1lf\n",*(int *)pNum,*(double *)pDecimal);

    return 0;
}