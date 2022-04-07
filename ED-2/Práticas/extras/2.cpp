/**
 * Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência Fibo-
 * nacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
*/

#include <bits/stdc++.h> 
using namespace std;

int fibonacci(int n){
    if(n < 3) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(void){
    int n = 0;
    scanf("%d", &n);
    printf("%d\n",fibonacci(n));
    return 0;
}