#include <stdio.h>

typedef int Item;

#define less(A,B) (A < B)

#define exch(A,B) {Item tt = A;\
                   A = B;\
                   B = tt;\
}
/**
7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3 7 3 2 5 4 3
*/
void selectionSort(Item *v, int l, int r){
    int min;
    for(int i = l; i < r; i++){
        min = i;
        for(int j = i+1; j <= r; j++){
            if(less(v[j], v[min])){
                min = j;
            }
        }
        exch(v[min], v[i]);
    }
}

void imprimirVetor(Item *v){
    int i = 0;
    while(v[i+1] != '\0'){
        printf("%d ", v[i]);
        i++;
    }
    printf("%d\n", v[i]);
}

int main(){
    int num, a = 0;
    Item vetor[1000];
    while(scanf("%d", &num) != EOF) vetor[a++] = num;
    vetor[a] = '\0'; 
    selectionSort(vetor, 0, a - 1);
    imprimirVetor(vetor);
    return 0;
}