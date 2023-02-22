#include <stdio.h>

typedef int Item;

#define less(A,B) (A < B)

#define exch(A,B) {Item tt = A; \
                   A = B; \
                   B = tt; \
                   }

#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

void bubbleSort(Item *v, int l, int r){
    for(int i = l; i < r; i++){
        for(int j = l; j < r; j++){
            cmpexch(v[j], v[j+1]);
        }
    }
}

void imprimeVetor(Item *v){
    int i = 0;
    while(v[i+1] != '\0'){
        printf("%d ", v[i++]);
    }
    printf("%d\n", v[i]);
}

int main(){
    Item vetor[1000];
    int num, a = 0;
    while(scanf("%d", &num) != EOF) vetor[a++] = num;
    vetor[a] = '\0';
    bubbleSort(vetor, 0, a - 1);
    imprimeVetor(vetor);  
    return 0;
}