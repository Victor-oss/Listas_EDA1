#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define lesseq(A,B) (A <= B)

#define eq(A,B) (A == B)

void merge(Item *v_in, int tam_in, Item *v_fim, int tam_fim){
    Item *v2 = (Item*) malloc(sizeof(Item)*(tam_fim + tam_in));
    int k = 0, i = 0, j = 0;
    while(i < tam_in && j < tam_fim){
        if(lesseq(v_in[i], v_fim[j])){
            v2[k++] = v_in[i++];
        } else {
            v2[k++] = v_fim[j++];
        }
    }
    while(i < tam_in){
        v2[k++] = v_in[i++];
    }
    while(j < tam_fim){
        v2[k++] = v_fim[j++];
    }
    for(k = 0; k < (tam_fim + tam_in); k++){
        v_in[k] = v2[k];
    }
    free(v2);
}

Item vetor[1000001], auxiliar[8000008];

int main(){
    int tam_aux = 0, tamanho = 0;
    for(int a = 0; a < 8; a++){
        scanf("%d", &tam_aux);
        for(int b = 0; b < tam_aux; b++){
            scanf("%d", &vetor[b]);
        }
        merge(auxiliar, tamanho, vetor, tam_aux);
        tamanho += tam_aux;
    }
    for(int b = 0; b < tamanho - 1; b++){
        printf("%d ", auxiliar[b]);
    }
    printf("%d\n", auxiliar[tamanho - 1]);
}


