#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4 
#define NOT_SORTED -5
#define SORTED -6

struct ALUNO{
  int matricula;
  char nome[30];
  float nota1, nota2,nota3;
};

typedef struct LINKED_LIST LIST;


LIST* list_create(void);
int list_free(LIST *list);


int list_push_front(LIST *list, struct ALUNO al); 
int list_push_back(LIST *list, struct ALUNO al); 
int list_insert(LIST *list, int pos, struct ALUNO al); 
int list_insert_sorted(LIST *list, struct ALUNO al); 


int list_size(LIST *list); 


int list_pop_front(LIST *list); 
int list_pop_back(LIST *list);
int list_erase_data(LIST *list, int mat); 
int list_erase_pos(LIST *list, int pos); 


int list_find_pos(LIST *list, int pos, struct ALUNO *al); 
int list_find_mat(LIST *list, int nmat, struct ALUNO *al); 
int list_front(LIST *list, struct ALUNO *al); 
int list_back(LIST *list, struct ALUNO *al); 
int list_get_pos(LIST *list, int nmat, int *pos);


int list_print(LIST *list);
int is_sorted(LIST *list);

