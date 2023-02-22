#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) (A < B)
#define eq(A,B) (A == B)

Item b;

void busca_binaria(Item *v, int l, int r){
    int meio = (r+l)/2;
    if(l >= r) {
        if(less(v[meio], b)){
            printf("%d\n", meio+1);    
        } else {
            printf("%d\n", meio);  
        }
        return;
    }
    if(eq(v[meio], b)){
        printf("%d\n", meio);
        return;
    } else if(less(b, v[meio]) && less(v[meio-1], b)){
        printf("%d\n", meio);
        return;
    } else if(less(v[meio], b)){
        busca_binaria(v, meio+1, r);
    } else if(less(b, v[meio])){
        busca_binaria(v, l, meio-1);
    }
} 

int main(){
    Item *vetor;
    int N, M;
    scanf("%d %d", &N, &M);
    vetor = (Item*) malloc(sizeof(Item)*N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &b);
        busca_binaria(vetor, 0, N-1);
    }
}