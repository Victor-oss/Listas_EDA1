#include <stdio.h>
#include <stdlib.h>

typedef struct{char caracter; int n_vezes; int posicao;} Item;

#define less(A,B) (A.n_vezes < B.n_vezes)

#define eq(A,B) (A.caracter == B.caracter)

#define exch(A,B) {Item tt = A; \
                   A = B; \
                   B = tt; \
}

void merge(Item *v, int l, int r1, int r2){
    int k = 0, i = l, j = r1+1;
    Item *v2 = (Item*) malloc(sizeof(Item)*(r2 - l + 1));
    while(i <= r1 && j <= r2){
        if(less(v[i], v[j])){
            v2[k++] = v[i++];
        } else {
            v2[k++] = v[j++];
        }
    }
    while(i <= r1){
        v2[k++] = v[i++];
    }

    while(j <= r2){
        v2[k++] = v[j++];
    }
    k = 0;
    for(i = l; i <= r2; i++){
        v[i] = v2[k];
        k++;
    }
    free(v2);
}

void mergeSort(Item *v, int l, int r){
    if(l>=r) return;
    int meio = (l+r)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    Item *vetor;
    int a = 0, sair = 0, novoa = 0, aux = 1;
    char qualquer;
    vetor = (Item*)malloc(sizeof(Item)*100000);
    while(sair == 0){
        scanf("%c", &qualquer);
        if(qualquer == '\n'){
            sair = 1;
        } else {
            vetor[a].caracter = qualquer;
            vetor[a].posicao = a;
            a++;
        }
    }
    for(int i = 1; i < a; i++){
        if(eq(vetor[i], vetor[novoa]) ){
            aux++;
            if(i == a - 1){
                vetor[novoa].n_vezes = aux;    
            }
        } else {
            vetor[novoa].n_vezes = aux;
            vetor[++novoa] = vetor[i];
            aux = 1;
            if(i == a - 1){
                vetor[novoa].n_vezes = aux;    
            }
        }
    }
    /*for(int i = 0; i <= novoa; i++){
        printf("%d %c %d\n", vetor[i].n_vezes, vetor[i].caracter, vetor[i].posicao);
    }
    printf("DIVISAO\n");*/
    mergeSort(vetor, 0, novoa);
    for(int i = novoa; i >= 0; i--){
        printf("%d %c %d\n", vetor[i].n_vezes, vetor[i].caracter, vetor[i].posicao);
    }
}