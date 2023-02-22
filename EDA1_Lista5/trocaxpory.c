#include <stdio.h>

void trocaxpory(char *v){
    if(*v == '\0'){
         printf("\n");
         return;
    }
    if(*v == 'x'){
        printf("y");
    } else {
        printf("%c", *v);
    }
    trocaxpory(v+1);
}

int main(){
    char vetor[81] ;
    scanf("%s", vetor);
    trocaxpory(vetor);
}