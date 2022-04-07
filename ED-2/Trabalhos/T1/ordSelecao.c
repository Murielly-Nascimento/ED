#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void troca(int v[], int i, int j){
	int temp = 0;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
    
    return;
}

void selecao(int v[], int ini, int fim, int min){
    if(ini == fim - 1) return;
    min = ini;
    for(int j = ini + 1 ; j < fim; j++) {
		if(v[j] < v[min]) // Se outro elemento for menor o min muda
			min = j;
	}
    troca(v,ini, min);
    selecao(v,ini+1,fim,min); 
}

int main(void){
    int v[10] = {0};
    for(int i = 0; i<10; i++)
        scanf("%d", &v[i]);
    selecao(v,0,10,0);
    for(int i = 0; i<10; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}