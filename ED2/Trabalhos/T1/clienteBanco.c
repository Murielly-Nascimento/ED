#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[20];
    int agencia;
}CLIENTE;

void troca(CLIENTE v[], int i,int j){
  CLIENTE temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int particao(CLIENTE v[],int esq,int dir){
  int i, fim;

  fim=esq;
  for(i=esq+1;i<=dir;i++){
    if((strcmp(v[i].nome,v[esq].nome)) < 0) {
       fim=fim+1;
       troca(v,fim,i);
    }
  }
  troca(v,esq,fim);
  return fim;
}

void quicksort(CLIENTE v[], int esq, int dir){
  int i;
  if(esq>=dir) return;
  i=particao(v,esq,dir);
  quicksort(v,esq,i-1);
  quicksort(v,i+1,dir);
}

void intercala(CLIENTE v[], int e, int m, int d){

 CLIENTE *r;  //vetor auxiliar dinâmico para armazenar a mistura
 int i,j,k;

 r = (CLIENTE *) malloc (((d+1)-e)*sizeof(CLIENTE));

 i=e;
 j=m+1;
 k=0;

 while ((i<=m)&&(j<=d)){
    if(v[i].agencia<=v[j].agencia){  //(trocar por <)
        r[k]=v[i];
        i++;
    }
    else{
        r[k]=v[j];
        j++;
    }
    k++;
 }

 while (i<=m) {r[k]=v[i]; i++; k++;}
 while (j<=d) {r[k]=v[j]; j++; k++;}

 //Copia do vetor auxiliar (contendo os dados ordenados) sobre o vetor original
 j=0;
 for(i=e;i<=d;i++){
     v[i]=r[j];
     j++;
 }

 free(r);
}

void mergesort (CLIENTE v[], int e, int d){
int m;
   if (e<d){
     m = (e+d)/2;
     mergesort(v,e,m);
     mergesort(v,m+1,d);
     //if (v[m]<v[m+1]) return;
     // não é necessaria a intercalação
	   intercala(v,e,m,d);
   }
}

int main(void){
    int N = 0;
    scanf("%d", &N);
    CLIENTE cliente[N];

    for(int i = 0; i<N; i++){
        scanf("%s", cliente[i].nome);
        scanf("%d", &cliente[i].agencia);
    }

    quicksort(cliente,0,N-1);
    mergesort(cliente,0,N-1);

	for(int i=0; i<N; i++){
        printf("%s ",cliente[i].nome);
        printf("%d\n",cliente[i].agencia);
    }

    return 0;
}