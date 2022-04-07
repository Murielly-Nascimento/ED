/*9) Receba uma palavra e imprima de trás-para-frente*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    char str[51]={'\0'};
    int tamanho=0;
    printf("<<Invertendo>>\n");
    printf("Digite a string : ");
    gets(str);
    tamanho = strlen(str);
    printf("Saída invertida: ");
    for(int i=tamanho;i>=0;i--) printf("%c",str[i]);
    printf("\n");
    return 0;
}