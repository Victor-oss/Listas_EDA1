#include <stdio.h>

unsigned char conta_pares(
    char *v, 
    unsigned char qtd){
    if(*(v+2) == '\0') return qtd;        
    if(*v == *(v+2)){
        return conta_pares(v+1, qtd+1);
    }
    return conta_pares(v+1, qtd);
}

int main(){
    char linha[201];
    unsigned char qtd_pares;
    scanf("%s", linha);
    qtd_pares = conta_pares(linha, 0);
    printf("%hd\n", qtd_pares);
}