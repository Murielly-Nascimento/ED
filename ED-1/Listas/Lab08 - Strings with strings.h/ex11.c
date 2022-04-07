/*11) Considere o seguinte programa
a) Qual é a função do programa?
    
    Verificar a senha digitada pelo usuário, e caso esteja correta 
    liberar o acesso ao usuário.

b) Qual a saída quando a senha correta é digitada (senha correta: 1234)
    
    Senha Correta
    Acesso liberado

c) Qual a saída para as seguintes senhas

a. 123
    
    Senha Errada
    Acesso Negado

b. 12345

    Senha Errada
    Acesso Negado

c. 123456

    Senha Errada
    Acesso Negado

d) Em quais casos o programa obteve um comportamento inválido. Explique o motivo.

    No caso c, porque o tamanho da string digitada pelo usuário excede o tamnanho 
    da stirng buff determinada no programa.

*/

#include <stdio.h>
#include <string.h>
int main(void)
{
    char buff[5];
    int pass = 0;
    printf("\n Entre com a senha : \n");
    gets(buff);
    if (strcmp(buff, "1234")) {
        printf ("\n Senha Errada \n");
    } else
    {
        printf ("\n Senha Correta \n");
        pass = 1;
    }
    if (pass) {
    /* O usuário acertou a senha, poderá continuar*/
        printf ("\n Acesso liberado \n");
    } else {
        printf ("\n Acesso negado \n");
    }
    return 0;
}