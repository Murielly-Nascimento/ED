//Arquivo .h do módulo pilhas

#ifndef _TStackh_
#define _TStackh_

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define EMPTY_STACK -5

//Definição da estrutura pilha
typedef struct TStack TStack;

//Funções de criação da pilha
TStack *stack_create(int tamanho);
int stack_free(TStack *st);

//Funções de manipulação da pilha
int stack_push(TStack *st, char palavra);
int stack_pop(TStack *st);
int stack_top(TStack *st, char *caracter);
int stack_empty(TStack *st);
int stack_full(TStack *st);
int stack_print(TStack *st);

#endif