/**
 * Faça uma função recursiva que permita somar os elementos de um vetor de inteiros
*/

#include <bits/stdc++.h> 
using namespace std;

int soma(int vetor[],int ini, int fim){
    if(ini >= fim) return vetor[0];
    else{
        vetor[0] += vetor[ini];
        return soma(vetor,ini+1,fim);
    }
}

int main(void){
    int vetor[5] = {0};
    for(int i = 0; i < 5; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d\n",soma(vetor,1,5));
    return 0;
}