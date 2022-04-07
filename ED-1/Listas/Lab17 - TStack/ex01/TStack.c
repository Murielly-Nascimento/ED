#include <stdio.h>
#include <stdlib.h>

#include "TStack.h"
#include "TSeqList.h"

// Wrapper com a biblioteca Lista Sequencial
struct TStack{
    List *list;
};

/*
*@brief Aloca espaço na heap para a st.
*/
TStack *stack_create(void){
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        //Se a alocação foi bem sucedida chamamos a função list_create da biblioteca TSeqList.
        st->list = create_list();
        if (st->list == NULL){
            //Se a alocação da lista foi mal sucedida liberamos o espaço alocado para a st.
            free(st);
            return NULL;
        }
    }
    return st;
}//stack_create.


/*
*@brief Libera espaço alocado na heap para a st.
*/
int stack_free(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL){
        //Se a st está vazia
        free(st);
        return EMPTY_STACK;
    }
    free_list(st->list);
    free(st);
}//stack_free

/*
*@brief Insere elementos no final da st
*/
int stack_push(TStack *st, struct aluno al){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_push_back(st->list, al);
}//stack_push

int stack_pop(TStack *st){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    pop_back(st->list);
    return SUCCESS;
}

int stack_top(TStack *st, struct aluno *al){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    return list_back(st->list, al);

}

int stack_empty(TStack *st){
    if(st == NULL) 
        return INVALID_NULL_POINTER;
    if(empty_list(st->list))
        return SUCCESS;
}

int stack_full(TStack *st){
    if(st == NULL) 
        return INVALID_NULL_POINTER;
    if(full_list(st->list))
        return SUCCESS;

}

int stack_print(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    print_list_reverse(st->list);
}

