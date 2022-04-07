#ifndef _TStackFloath_
#define _TStackFloath_

//Mensagens de erro e sucesso
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define EMPTY_STACK -5

//Definição da estrutura pilha de valores
typedef struct TStackFloat TStackFloat;

//Funções de criação da pilha
TStackFloat *stack_create_float(int tamanho);
int stack_free_float(TStackFloat *st);

//Funções de manipulação da pilha
int stack_push_float(TStackFloat *st, float valor);
int stack_pop_float(TStackFloat *st);
int stack_top_float(TStackFloat *st, float *valor);
int stack_empty_float(TStackFloat *st);
int stack_full_float(TStackFloat *st);
int stack_print_float(TStackFloat*st);

int desempilhaFloat(TStackFloat *st, float *valor);

#endif