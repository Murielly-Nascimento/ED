/*12) a) Pense em uma solução para o problema do exercício 11 que utiliza fgets.
Considere que o tamanho máximo de uma senha são 4 dígitos.

b) Teste com os seguintes valores
a. 123
b. 12345
c. 123456*/

#include <stdio.h>
#include <string.h>
int main(void)
{
    char buff[5];
    int pass = 0,tamanho=0;
    printf("\n Entre com a senha : \n");

    fgets(buff,7,stdin);
    buff[strcspn(buff, "\n")] = '\0';
    tamanho =strlen(buff);

    if (strcmp(buff, "1234")!=0 || tamanho>4) {
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