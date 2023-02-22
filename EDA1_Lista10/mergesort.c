#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) (A < B)

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = (Item*) malloc(sizeof(Item) * (r2 - l + 1));
    int k = 0, i = l, j = r1 + 1;
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
        v[i] = v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, int l, int r){
    if(l >= r) return;
    int meio = (l+r)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    Item *vetor; 
    int num;
    scanf("%d", &num);
    vetor = (Item*) malloc(sizeof(Item)*num);
    for(int a = 0; a < num; a++){
        scanf("%d", &vetor[a]);
    }
    mergeSort(vetor, 0, num-1);
    printf("%d", vetor[0]);
    for(int a = 1; a < num; a++){
         printf(" %d", vetor[a]);
    }
    printf("\n");
}