#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(void){

  printf("\n<<CRIANDO A LISTA DUPLAMENTE ENCADEADA>>\n");

  struct aluno a,b,c,d;
  strcpy(a.nome,"Joao");
  a.matricula = 1;
  a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

  strcpy(b.nome,"Maria");
  b.matricula = 2;
  b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

  strcpy(c.nome,"Jose");
  c.matricula = 3;
  c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

  strcpy(d.nome,"Ana");
  d.matricula = 4;
  d.n1 = 0;    d.n2 = 0;    d.n3 = 2;

  List *list;
  list = list_create();

  printf("\n<< INSERINDO ELEMENTOS >>\n");
  printf("Insere aluno a no início\n");
  list_push_front(list,a);

  printf("Insere aluno b no fim\n");
  list_push_back(list,b);

  printf("Digite uma posição: ");
  int posicao = 0;
  scanf("%d",&posicao);
  int sucesso = list_insert(list,posicao,c);
  switch(sucesso){
    case 0: printf("Deu certo!\n");
    break;
    case -1: printf("INVALID_NULL_POINTER\n");
    break;
    case -2: printf("OUT_OF_MEMORY\n");
    break;
    case -3: printf("OUT_OF_RANGE\n");
    break;
  }

  printf("Insere aluno d no fim\n");
  list_push_back(list,d);  

  printf("\n<<IMPRIME A LISTA DE FRENTE PARA TRÁS>>\n");
  list_print_forward(list);

  printf("\n<<IMPRIME A LISTA DE TRÁS PARA FRENTE>>\n");
  list_print_reverse(list); 

  printf("\n<< ENCONTRANDO ELEMENTOS >>\n");
  struct aluno aux;
  printf("Digite uma posição: ");
  scanf("%d",&posicao);
  list_find_pos(list, posicao, &aux);
  printf("Na posição %d está o(a) aluno(a) %s\n",posicao,aux.nome);

  int matricula = 0;
  printf("Digite uma matricula: ");
  scanf("%d",&matricula);
  list_find_mat(list, matricula, &aux);
  printf("O aluno de matrícula %d é %s\n",matricula,aux.nome);

  printf("O aluno na frente da lista é: ");
  list_front(list, &aux);
  printf("%s\n",aux.nome);

  printf("O aluno no final da lista é: ");
  list_back(list, &aux);
  printf("%s\n",aux.nome);

  printf("Digite uma matricula: ");
  scanf("%d",&matricula);
  list_get_pos(list, matricula, &posicao);
  printf("O aluno de matrícula %d esta na posicao %d\n",matricula,posicao);

  printf("\n<< REMOVE QUALQUER ELEMENTO >>\n");
  printf("Digite uma posição: ");
  scanf("%d",&posicao);
  sucesso = list_erase(list,posicao);
  list_print_forward(list);

  printf("\n<< REMOVE O PRIMEIRO ELEMENTO >>\n");
  list_pop_front(list);
  list_print_forward(list);
  
  printf("\n<< REMOVE O ÚLTIMO ELEMENTO >>\n");
  list_pop_back(list);
  list_print_forward(list);

  printf("\n<<LIBERA A LISTA>\n");
  list_free(list);   

  return 0;
}