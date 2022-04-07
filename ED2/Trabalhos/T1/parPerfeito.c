#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    char nome[20];
    char sexo;
    int idade;
}PESSOA;

void intercala(PESSOA v[], int e, int m, int d){
    PESSOA *r;  //vetor auxiliar dinâmico para armazenar a mistura
    int i,j,k;

    r = (PESSOA *) malloc (((d+1)-e)*sizeof(PESSOA));

    i=e;
    j=m+1;
    k=0;

    while ((i<=m)&&(j<=d)){
        if(v[i].idade<=v[j].idade){  
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

void troca(PESSOA v[], int i,int j){
  PESSOA temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

void mergesort (PESSOA v[], int e, int d){
    int m;
    if (e<d){
        m = (e+d)/2;
        mergesort(v,e,m);
        mergesort(v,m+1,d);
        intercala(v,e,m,d);
    }
    return;
}

PESSOA * ordBolha (PESSOA v[], int n) {
    int i, j;
    PESSOA *masculino;
    PESSOA temp;
    char troca;

    troca = 'v';

    for (i=n-1; (i >= 1) && (troca == 'v'); i--)  {
        troca = 'f';
        for (j= 0; j < i ;j++) {
            if((v[j].sexo == 'm') && (v[j+1].sexo=='f')) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 'v';
                masculino = &(v[j+1]);
            }
        }
    }

    return masculino;
}

int main(void){
    int N = 0;
    scanf("%d", &N);

    PESSOA pessoa[N];
    for(int i = 0; i < N; i++){
        scanf("%s", pessoa[i].nome);
        scanf(" %c", &pessoa[i].sexo);
        scanf("%d", &pessoa[i].idade);
    }

    mergesort(pessoa,0,(N-1));
    PESSOA* masculino = ordBolha(pessoa,N);
    
    int i = 0, casais = 0;
    while(pessoa[i].sexo=='f'){
        if((pessoa[i].idade + masculino->idade)%2 == 0) casais++;
        i++; masculino++;
    }
    printf("%d\n", casais);
    return 0;
}
