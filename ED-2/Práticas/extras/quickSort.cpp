#include <bits/stdc++.h> 
using namespace std;

void quicksort(int v[], int esq, int dir);
int particao(int v[],int esq,int dir);
void troca(int v[], int i, int j);


void quicksort(int v[], int esq, int dir){
    //Esquerda é o início do vetor e direita é o fim
	int i = 0;
	if(esq>=dir) return ;   //Condição de parada
	i = particao(v,esq,dir); //Devolve a posição onde cai o pivô
	quicksort(v,esq,i-1);   //Lista dos menores
	quicksort(v,i+1,dir);   //Lista dos maiores

    return;
}

/*  Parte o vetor em duas metadas, de preferência equilibradas e 
*   volta a posição onde o pivô se encontra.*/
int particao(int v[],int esq,int dir){
	int i = 0, fim = 0;
	
    printf("\n Subvetor:\n");
	for(i=esq; i<=dir; i++) 
        printf("%d ",v[i]); 
    printf("\n");
	fim = esq; //Fim da lista dos menores
	
    for(i=esq+1;i<=dir;i++){
	    if(v[i]>v[esq]) {
	        fim=fim+1;
	        troca(v,fim,i);
	    }
    }

	troca(v,esq,fim);
	for(i=esq; i<=fim; i++) 
        printf("%d ",v[i]); 
    printf("\n");
	
    for(i=fim+1; i<=dir; i++) 
        printf("%d ",v[i]); 
    printf("\n");
	
    return fim;
}

void troca(int v[], int i, int j){
	int temp = 0;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
    
    return;
}

#define N 16

int main(void){
	int i = 0,a[N];
	
    for(i=0; i<N; i++) a[i]=rand()%100;
	for(i=0; i<N; i++) printf("%d ",a[i]);
    quicksort(a,0,N-1);

	printf("\n Ordenado:\n");
	for(i=0; i<N; i++) printf("%d ",a[i]);
    printf("\n");
	
    return 0;
}