#include<stdio.h>
#include <stdlib.h>

void troca(int v[], int i,int j){
  int temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int particao(int v[],int esq,int dir){
  int i, fim;

  fim=esq;
  for(i=esq+1;i<=dir;i++){
    if(v[i]<v[esq]) {
       fim=fim+1;
       troca(v,fim,i);
    }
  }
  troca(v,esq,fim);
  return fim;
}

void quicksort(int v[], int esq, int dir){
    int *menores, *maiores, i = 0, j = 0;
    menores = malloc((dir - esq + 1) * sizeof(int));
    maiores = malloc((dir - esq + 1) * sizeof(int));
    menores[0] = esq;
    maiores[0] = dir;

    while(i >= 0){
        esq = menores[i]; 
        dir = maiores[i]; 
        i--; 
        while(esq < dir){
            j = particao(v,esq,dir);
            i++; 
            menores[i] = esq; 
            maiores[i] = j-1;
            esq = j + 1;
        }
    }
    return;
}

int main(void){
	int N = 0;
    scanf("%d", &N);
    int a[N];
	
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    quicksort(a,0,N-1);

	for(int i=0; i<N; i++) printf("%d ",a[i]);
    printf("\n");
	
    return 0;
}
