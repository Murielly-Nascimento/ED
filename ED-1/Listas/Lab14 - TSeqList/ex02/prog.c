#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "TVarSeqList.h"

int main(void) {
  struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},{4,"Ricardo",7.5,8.7,6.8  },{1,"Bianca",9.7,6.7,8.4 },{3,"Ana",5.7,6.1,7.4}};
  struct aluno aux = {0};
  int size_lista = MAX;

  printf("\n<< CRIA LISTA >>\n");
  List *li = create_list(size_lista);
  for(int i=0;i<4;i++)
    list_insert_sort(li, a[i]);
  
  print_list(li);
  printf("\n\n\n");
  
  printf("\n<< CONSULTA LISTA >>\n");
  printf("Digite uma posição: ");
  int pos = 0;
  scanf("%d",&pos);
  list_find_pos(li, pos, &aux);
  printf("Matricula: %d\n",aux.matricula);
  printf("Nome: %s\n",aux.nome);
  printf("Notas: %f %f %f\n",aux.n1,aux.n2,aux.n3);

  printf("\n<< CONSULTA MATRICULA >>\n");
  printf("Digite uma matricula: ");
  int mat = 0;
  scanf("%d",&mat);
  list_find_mat(li, mat, &aux);
  printf("Matricula: %d\n",aux.matricula);
  printf("Nome: %s\n",aux.nome);
  printf("Notas: %f %f %f\n",aux.n1,aux.n2,aux.n3);

  printf("\n<< INSERE NO FINAL >>\n");
  aux.matricula = 6;
  strcpy(aux.nome,"Elena");
  aux.n1 = 10; aux.n2 =10; aux.n3 = 10;
  list_push_back(li, aux);
  print_list(li);

  printf("\n<< INSERE NO INICIO >>\n");
  aux.matricula = 8;
  strcpy(aux.nome,"Mercedes");
  aux.n1 = 8; aux.n2 =10; aux.n3 = 10;
  list_push_front(li, aux);
  print_list(li);

  printf("\n<< REMOVENDO ELEMENTOS DA LISTA PELA MATRICULA >>\n");
  printf("Removendo aluno de matrícula 2\n");
  mat = a[0].matricula;
  optimal_list_erase(li, mat);
  print_list(li);

  printf("\n<< REMOVE INICIO >>\n");
  pop_front(li);
  print_list(li);

  printf("\n<< REMOVE FINAL >>\n");
  pop_back(li);
  print_list(li);

  printf("\n<< TAMANHO DA LISTA >>\n");
  int tamanho = list_size(li);
  printf("Tamanho da lista: %d\n",tamanho);

  printf("\n<< ESTADO DA LISTA >>\n");
  if(full_list(li) == 0) printf("A lista está cheia\n");
  else if(empty_list(li) == 0) printf("A lista está vazia\n");
  else printf("Ainda há espaço na lista\n");

  printf("\n<< COMPACTANDO A LISTA >>\n");
  compact_list(li);
  print_list(li);

  printf("\n << ESVAZIANDO LISTA >>\n");
  for(int i = 0; i<tamanho;i++){
    pop_back(li);
    printf("\n\n\n");
    print_list(li);
  }

  free_list(li);
  printf("\n<< FIM DO PROGRAMA >>\n");
  
  return 0;
}
