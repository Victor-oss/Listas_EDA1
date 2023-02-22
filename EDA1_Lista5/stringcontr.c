#include <stdio.h>

void imprimeContrario(char *v){
    if(*v == '\0') return;
    imprimeContrario(v+1);
    printf("%c", *v);
}

int main(){
    char vetor[501];
    scanf("%s", vetor);
    imprimeContrario(vetor);
    printf("\n");
}