#include<stdio.h>

int main(void)
{
    int v1 = 1;
    double v2 = 2;
    char c = 'a';
    int *p_v1;
    double *p_v2;
    char *p_c;

    p_v1 = &v1;
    p_v2 = &v2;
    p_c = &c;

    printf("\nEndereço de v1 %u", p_v1);
    printf("\nEndereço de v2 %u", p_v2);
    printf("\nEndereço de c %u\n", p_c);

    printf("\nEndereço+1 de v1 %u", p_v1+1);
    printf("\nEndereço+1 de v2 %u", p_v2+1);
    printf("\nEndereço+1 de c %u\n", p_c+1);

    printf("\nEndereço-1 de v1 %u", p_v1-1);
    printf("\nEndereço-1 de v2 %u", p_v2-1);
    printf("\nEndereço-1 de c %u\n", p_c-1);


    printf("\nEndereço+2 de v1 %u", p_v1+2);
    printf("\nEndereço+2 de v2 %u", p_v2+2);
    printf("\nEndereço+2 de c %u\n", p_c+2);
    
    printf("\nEndereço-2 de v1 %u", p_v1-2);
    printf("\nEndereço-2 de v2 %u", p_v2-2);
    printf("\nEndereço-2 de c %u\n", p_c-2);

    return 0;
}