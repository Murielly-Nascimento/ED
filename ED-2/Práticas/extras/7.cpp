/**
 * Crie um programa em C que receba um vetor de números reais com 100 elementos.
 * Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.
*/

#include <bits/stdc++.h> 
using namespace std;

int reverte(double vetor[], int ini, int fim){
    if(ini == fim) return 1;
    else{
        double aux = vetor[ini];
        vetor[ini] = vetor[fim];
        vetor[fim] = aux;
        return reverte(vetor, ini+1, fim-1); 
    }
}

int main(void){
    double vetor[5] = {1.5,2,3,4,5};
    reverte(vetor,0,4);
    for(int i = 0; i < 5; i++){
        printf("%.1lf ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}