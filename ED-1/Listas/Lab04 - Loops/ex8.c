/*8) Refaça o exercício anterior utilizando o comando do .. while; Discuta por que o do-while não é a
melhor estrutura para resolver este exercício.*/

#include<stdio.h>

int main(void){
    int i=0;
    printf("<< Contagem progressiva até 0 >>\n");
    printf("Qual é o número inicial?");
    scanf("%d",&i);
    do{
        printf("%d..",i);
        i++;
    } while(i<=0);
    printf("FIM!\n");
    return 0;
}

/*Do while é usado quando o programador deseja que os passos sejam executados
antes que o programa verifique as condições determinadas pelo laço. Nesse caso, 
a estrutura for ou while são mais indicadas*/