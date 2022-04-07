#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4 

struct aluno{
  int matricula;
  char nome[30];
  float n1, n2,n3;
};

typedef struct circlist CircList;

CircList* clist_create(void);
int clist_free(CircList *clist);

int clist_push_front(CircList *clist, struct aluno al);
int clist_push_back(CircList *clist, struct aluno al);

int clist_pop_front(CircList *clist);
int clist_pop_back(CircList *clist);

int clist_print(CircList *clist);

int list_find_next(CircList *clist,int *chamadas,struct aluno *al);

