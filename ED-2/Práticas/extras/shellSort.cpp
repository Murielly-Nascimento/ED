#include <bits/stdc++.h> 
using namespace std;

void shellsort(int v[], int n) {
    int i, j, h = 1;
    int aux;

    do { h = h * 3 + 1;
    } while (h < n);

    do {
        h /= 3;
        for(i = h ; i < n ; i++) {
            aux = v[i];
            j = i;
            while (v[j - h] > aux) {
                v[j] = v[j - h];
                j -= h;
                if (j < h) break;
            }
            v[j] = aux;
        }
        printf("\n Semi-Ordenado:\n");
	    for(i=0; i<n; i++) printf("%d ",v[i]);
        printf("\n");
    } while (h != 1);
}

#define N 16

int main(void){

    int i = 0,a[N];
	
    for(i=0; i<N; i++) a[i]=rand()%100;
	for(i=0; i<N; i++) printf("%d ",a[i]);
    shellsort(a,N);

	printf("\n Ordenado:\n");
	for(i=0; i<N; i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}