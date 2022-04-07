#include <bits/stdc++.h> 
using namespace std;


void intercala (int v[], int e, int m, int d){
    int *r; //vetor auxiliar para armazenar a mistura
    int i,j,k;

    r = (int *) malloc (((d+1)-e)*sizeof(int));

    i=e;
    j=m+1;
    k=0;
    
    while ((i<=m)&&(j<=d)){ // intercala enquanto nenhuma das partes do vetor
        if(v[i]<=v[j]){ // foi consumida totalmente
            r[k]=v[i];
            i++; 
        }
        else{
            r[k]=v[j];
            j++; 
        }
        k++;
    }
    while (i<=m) {r[k]=v[i];i++;k++;} //termina de intercalar se sobrou à esquerda
    while (j<=d) {r[k]=v[j];j++;k++;} //termina de intercalar se sobrou à direita

    //Cópia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
    j=0;
    for(i=e;i<=d;i++){ v[i]=r[j]; j++; }

    free(r);
}

void mergesort (int v[], int e, int d){
    int m;
    
    if (e<d){
        m = (e+d)/2;
        mergesort(v,e,m);
        mergesort(v,m+1,d);
        if(v[m] > v[m+1]) intercala(v,e,m,d);
    }
}

#define N 16

int main(void){
	int i = 0,a[N];
	
    for(i=0; i<N; i++) a[i]=rand()%100;
	for(i=0; i<N; i++) printf("%d ",a[i]);
    mergesort(a,0,N-1);

	printf("\n Ordenado:\n");
	for(i=0; i<N; i++) printf("%d ",a[i]);
    printf("\n");
	
    return 0;
}