#include <stdio.h>
#include <stdlib.h>
int main(){
    short int *vals, n_pessoas;
    int palpite,total;
    scanf("%hd", &n_pessoas);
    vals = (short int*)malloc(n_pessoas*sizeof(short int));
    total = 0;
    for(int i = 0; i<(n_pessoas-1); i++){
        scanf("%hd ", &vals[i]);
        total += vals[i];
    }
    scanf("%hd", &vals[n_pessoas - 1]);
    total += vals[n_pessoas - 1];
    scanf("%d", &palpite);
    if(total == palpite){
        printf("Acertou\n");
    } else {
        printf("Errou\n");
    }
}