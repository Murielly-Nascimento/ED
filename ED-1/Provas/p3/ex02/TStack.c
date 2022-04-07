#include <stdio.h>
#include <stdlib.h>

#include "TStack.h"
#include "TLinkedList.h"

struct TStack{
    LIST *list;
};

TStack *stack_create(void){
    TStack *st;
    st = malloc(sizeof(TStack));
    if(st != NULL){
        st->list = list_create();
        if(st->list == NULL){
            free(st);
            return NULL;
        }
    }
    return st;
}

int stack_free(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    list_free(st->list);
    free(st);
}

int stack_push(TStack *st, struct aluno al){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    return list_push_front(st->list, al);
}

int stack_pop(TStack *st){
    if (st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    list_pop_back(st->list);
    return SUCCESS;
}

int stack_top(TStack *st, struct aluno *al){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    return list_front(st->list, al);

}

int stack_empty(TStack *st){
    if(st == NULL) 
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return SUCCESS;
}

int stack_full(TStack *st){
    if(st == NULL) 
        return INVALID_NULL_POINTER;
    return FULL_STACK;
}

int stack_print(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->list == NULL)
        return EMPTY_STACK;
    list_print(st->list);
}