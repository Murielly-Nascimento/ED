#include <bits/stdc++.h> 
using namespace std;


void trocah(int *A, int p, int m){
   int temp;
   temp = A[p];
   A[p] = A[m];
   A[m] = temp;
}

int esq (int pos){
   return (pos*2)+1;
}

int dir (int pos){
   return (pos*2)+2;
}

/* FUNÇÃO max-heapify
* A função max-heapify deixa que o valor A[i] “flutue para
* baixo”, de maneira que a subárvore com raiz no índice i se
* torne um heap
*/
void heap_maximo_pos(int *A, int pos, int tam_heap){
int e,d,maior;
   
   for(int i = pos; i <= tam_heap; i++){
        e = esq(i);
        d = dir(i);
        if ((e <= tam_heap) && (A[e] > A[i]))
            maior = e;
        else maior = i;
        if ((d <= tam_heap) && (A[d] > A[maior]))
            maior = d;
        if (maior != i) {
            trocah(A,i,maior);
        }
   }
}

/*FUNÇÃO build-max-heap
*O procedimento build-max-heap percorre os nós restantes
*da árvore e executa max-hepify sobre cada um
*/
void construir_heap_max(int *A,  int fim){
int i;
  for(i=(fim-1)/2; i>=0; i--){
      heap_maximo_pos(A,i,fim);
  }
}

/* FUNÇÃO heapsort
* 1) Construir um heap, usando a função build-max-heap
* 2) Trocar o elemento A[1] com A[n], e atualiza o tamanho do heap para n − 1
* 3) Corrigir o heap com a função max-heapify e repetir o processo
*/
void heapsort(int *A, int fim){
int i,tam_heap;
   tam_heap = fim;
   construir_heap_max(A,fim);
   for (i = fim; i>=0; i--){
      trocah(A,0,i);
      tam_heap--;
      heap_maximo_pos(A,0,tam_heap);
   }
}

#define N 16

int main(void){

    int i = 0,a[N];
	
    for(i=0; i<N; i++) a[i]=rand()%100;
	for(i=0; i<N; i++) printf("%d ",a[i]);
    heapsort(a,N-1);

	printf("\n Ordenado:\n");
	for(i=0; i<N; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}