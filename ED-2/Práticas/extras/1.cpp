/*
 * Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.
*/

#include <bits/stdc++.h> 
using namespace std;

int fatorial(int n){
    if(n == 1) return 1;
    else return n*fatorial(n-1);
}

int main(void){
    int n = 0;
    scanf("%d", &n);
    printf("%d\n",fatorial(n));

    return 0;
}