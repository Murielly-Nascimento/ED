/*
11) Faça um programa que faça operações simples de números complexos:
• Crie e leia dois números complexos z e w, compostos por parte real e parte imaginária.
• Apresente a soma, subtração e produto entre z e w, nessa ordem, bem como o
módulo de ambos.
• Obs: faça #include <math.h> e use a função sqrt() para calcular a raiz de um número
*/

#include<stdio.h>
#include<math.h>

int main(void){
    double Z = 0.0, Z_i = 0.0, W = 0.0, W_i=0.0;
    
    printf("<<Numero complexo>>\n");
    printf("Informe a parte real de z:");
    scanf("%lf",&Z);
    printf("Informe a parte imaginária de z:");
    scanf("%lf",&Z_i);
    printf("Informe a parte real de w:");
    scanf("%lf",&W);
    printf("Informe a parte imaginária de w:");
    scanf("%lf",&W_i);

    printf("z + w = %.1lf + %.1lfi\n", Z + W,Z_i + W_i);
    printf("z + w = %.1lf + %.1lfi\n", Z - W,Z_i - W_i);
    printf("z * w = %.1lf + %.1lfi\n", (Z * W - Z_i * W_i),(Z * W_i + Z_i * W));
    printf("|z| =%.4lf\n",sqrt(pow(Z,2) + pow(Z_i,2)));
    printf("|w| =%.4lf\n",sqrt(pow(W,2) + pow(W_i,2)));
    
    return 0;
}