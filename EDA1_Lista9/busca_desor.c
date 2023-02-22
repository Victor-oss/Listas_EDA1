#include <stdio.h>
#include <stdlib.h>

typedef struct{int valor; int posicao;} Item;

#define less(A,B) (A.valor < B.valor)

#define equals(A,B) (A.valor == B.valor)

#define exch(A,B) {Item tt = A; \
                   A = B; \
                   B = tt; \
}

#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

Item b;

void selectionSort(Item *v, int l, int r){
    Item aux;
    int j;
    for(int i = r; i > l; i--){
        cmpexch(v[i], v[i-1]);
    }    
    for(int i = l+2; i <= r; i++){
        j = i;
        aux = v[j];
        while(less(aux, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
}

int bb(Item *v, int l, int r){
    if(r<l){
        return -1;
    }
    int meio = (l+r)/2;
    if(equals(b, v[meio])){
        return v[meio].posicao;
    }else if(less(v[meio], b)){
        return bb(v, meio+1, r);
    } else if(less(b, v[meio])){
        return bb(v, l, meio-1);
    }
}

int main(){
    int N, M;
    Item *vetorN;
    scanf("%d %d", &N, &M);
    vetorN = (Item*) malloc(N*sizeof(Item));
    for(int i = 0; i < N; i++){
        scanf("%d", &vetorN[i].valor);
        vetorN[i].posicao = i;
    }
    selectionSort(vetorN, 0, N-1);
    for(int i = 0; i < M; i++){
        scanf("%d", &b.valor);
        printf("%d\n", bb(vetorN, 0, N-1));
    }
}