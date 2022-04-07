#include<stdio.h>

int main(void){

    int val[5] = {2,4,5,8,10};
    unsigned int *endereco = &val;
    printf("<< PONTEIRO >>\n");
    
    for(int i=0;i<5;i++){
        printf("val[%d] = %d\n",i,*endereco);
        endereco++;
    } 

    return 0;
}

/* 5)	Os operadores + e – funcionam com ponteiros. Chamamos de aritmética de ponteiros. 
Considere o código abaixo. Complete o código e preencha a tabela abaixo com os endereços de cada printf.

*** modificar o especificador de formato no printf caso seja necessário

+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
| Nome variável               |                   |                   |                 |                   |                   |
| / Endereços                 | Endereço var-2    | Endereço var-1    | Endereço var    | Endereço var+1    | Endereço var+2    |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             |                   |                   |                 |                   |                   |
| p_v1                        |                   |                   |                 |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             |                   |                   |                 |                   |                   |
| p_v2                        |                   |                   |                 |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             |                   |                   |                 |                   |                   |
| p_c                         |                   |                   |                 |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
*/