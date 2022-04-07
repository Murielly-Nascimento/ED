#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TStack.h"

#define MAX 100

int bemFormada(char *str){
    TStack *pilha = stack_create(strlen(str) + 1);
    for(int i = 0; str[i] != '\0'; i++){
        char caracter = '\0';
        switch (str[i])
        {
        case ')':
            if(stack_empty(pilha) == 0) return 0;
            stack_top(pilha,&caracter);
            stack_pop(pilha);
            if(caracter != '(') return 0;
            break;
        case ']':
            if(stack_empty(pilha) == 0) return 0;
            stack_top(pilha,&caracter);
            stack_pop(pilha);
            if(caracter != '[') return 0;
            break;
        default: stack_push(pilha,str[i]);
        }
    }
    return 1;
}

int main(void){
  
    printf("\n<< BEM FORMADA >>\n");
    char str[MAX] = {'\0'};
    printf("Digite uma sequencia de '(', '[' e '{'\n");
    scanf("%s", str);

    int sucesso = bemFormada(str);
    if(sucesso == 1) printf("Sequência bem formada\n");
    else printf("Sequência mal formada\n");


  return 0;
}