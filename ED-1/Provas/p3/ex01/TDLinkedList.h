#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define EMPTY_LIST -5

struct aluno{
 int matricula;
 char nome[30];
 float n1,n2,n3;
};

typedef struct DlinkedList List;

List* list_create(void);
int list_free(List *list);

int list_push_front(List *list, struct aluno al);
int list_push_back(List *list, struct aluno al);
int list_insert(List *list, int pos, struct aluno al);

int list_size(List *list);

int list_pop_front(List *list);
int list_pop_back(List *list);
int list_erase(List *list, int pos);

int list_find_pos(List *list, int pos, struct aluno *al);
int list_find_mat(List *list, int nmat, struct aluno *al);
int list_front(List *list, struct aluno *al);
int list_back(List *list, struct aluno *al);
int list_get_pos(List *list, int nmat, int *pos);

int list_print_forward(List *list);
int list_print_reverse(List *list);

int list_erase_zeros(List *list);

int list_splice(List *dest, List *source, int pos);


