//Arquivo ListaSequencial.h
#ifndef _TSeqListh_
#define _TSeqListh_

#define MAX 100
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define EMPTY_LIST -5

#include "aluno.h"

typedef struct list List;

List* create_list();
int free_list(List* li);

int consult_list_pos(List* li, int pos, struct aluno *al);
int consult_list_mat(List* li, int mat, struct aluno *al);
int list_back(List* li, struct aluno *al);

int list_push_back(List* li, struct aluno al);
int list_push_front(List* li, struct aluno al);
int list_insert_sort(List* li, struct aluno al);

int list_erase_data(List* li, int mat);
int pop_front(List* li);
int pop_back(List* li);

int list_size(List* li);

int full_list(List* li);
int empty_list(List* li);

int print_list(List* li);
int print_list_reverse(List *li);
int optimal_list_erase(List* li, int mat);

#endif
