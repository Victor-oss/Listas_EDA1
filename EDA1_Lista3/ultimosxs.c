#include <stdio.h>

void xs_no_final(char* posicao){
    if(*posicao == '\0') return;
    if(*posicao == 'x'){
        xs_no_final(posicao+1);
        printf("%c", *posicao);
    }else{
        printf("%c", *posicao);
        xs_no_final(posicao+1);
    }
}

int main(){
    char vetor[101];
    scanf("%s", vetor);
    xs_no_final(vetor);
    printf("\n");
}