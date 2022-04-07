#ifndef _TQueue_
#define _TQueue_

#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4 
#define EMPTY_QUEUE -5

#include "aluno.h"

typedef struct TQueue TQueue;

TQueue* queue_create(void);
int queue_free(TQueue *queue);

int queue_push(TQueue *queue, struct aluno al);
int queue_pop(TQueue *queue);
int queue_top(TQueue *queue,struct aluno *al);

//int queue_empty(TQueue *queue);
//int queue_full(TQueue *queue);
int queue_print(TQueue *queue);

#endif