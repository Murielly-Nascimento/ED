#include<stdio.h>

int main(void){

    int val[5] = {2,4,5,8,10};
    int *endereco = val;
    printf("<< PONTEIRO >>\n");
    
    for(int i=0;i<5;i++){
   	    *endereco = (*endereco)-1;
        printf("val[%d] = %d\n",i,*(endereco));
        endereco++;
    } 

    return 0;
}