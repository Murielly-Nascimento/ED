#ifndef _TSeqQueue_
#define _TSeqQueue_

#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4 
#define EMPTY_QUEUE -5

#include "aluno.h"

typedef struct TSeqQueue TSeqQueue;

TSeqQueue* queue_create(int size);
int queue_free(TSeqQueue *queue);

int queue_push(TSeqQueue *queue, struct aluno al);
int queue_pop(TSeqQueue *queue);
int queue_top(TSeqQueue *queue,struct aluno *al);

int queue_empty(TSeqQueue *queue);
int queue_full(TSeqQueue *queue);
int queue_print(TSeqQueue *queue);

int compact_list(TSeqQueue *queue);

#endif