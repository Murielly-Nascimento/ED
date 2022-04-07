/**
 * Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório
 * dos números de 1 a N.
*/

#include <bits/stdc++.h> 
using namespace std;

int soma(int ini, int n, int aux){
    if(ini > n) return aux;
    else{
        aux += ini;
        return soma(ini+1,n,aux); 
    }
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    printf("%d\n",soma(0,n,0));
    return 0;
}