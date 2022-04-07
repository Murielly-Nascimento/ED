/**
 * Crie um programa em C, que contenha uma função recursiva que receba dois inteiros
 * positivos k e n e calcule k n . Utilize apenas multiplicações. O programa principal deve
 * solicitar ao usuário os valores de k e n e imprimir o resultado da chamada da função.
*/

#include <bits/stdc++.h> 
using namespace std;

int pot(int k, int n){
    if(n == 0) return 1;
    else{
        return k*pot(k, n-1); 
    }
}

int main(void){
    int k = 0, n = 0;
    scanf("%d %d",&k, &n);
    printf("%d\n",pot(k,n));
    return 0;
}