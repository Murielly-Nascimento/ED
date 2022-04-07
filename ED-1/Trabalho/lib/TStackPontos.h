#ifndef _TStackPontosh_
#define _TStackPontosh_

//Mensagens de erro e sucesso
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define EMPTY_STACK -5

//Definição da estrutura pilha de valores
typedef struct TStackPontos TStackPontos;

typedef struct{
    int x;
    int y;
    int valor;
}PONTOS;

//Funções de criação da pilha
TStackPontos *stack_create_int(int tamanho);
int stack_free_int(TStackPontos *st);

//Funções de manipulação da pilha
int stack_push_int(TStackPontos *st, PONTOS valor);
int stack_pop_int(TStackPontos *st);
int stack_top_int(TStackPontos *st, PONTOS *valor);
int stack_empty_int(TStackPontos *st);
int stack_full_int(TStackPontos *st);
int stack_print_int(TStackPontos*st);

int desempilhaInt(TStackPontos *st, PONTOS *valor);

#endif