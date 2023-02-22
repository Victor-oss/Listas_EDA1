#include <stdio.h>
#include <stdlib.h>

typedef struct{int valor; char comando[16];} Item;

#define less(A,B) (A.valor < B.valor)

#define equals(A,B) (A.valor == B.valor)

#define exch(A,B){Item tt = A; \
                  A = B; \
                  B = tt; \
}

#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

Item b;

void insertionSort(Item *v, int l, int r){
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

void bb(Item *v, int l, int r){
    int meio = (l+r)/2;
    if(l > r){
        printf("undefined\n");
        return;
    }
    if(equals(b,v[meio])){
        printf("%s\n", v[meio].comando);
        return;
    }
    if(less(b,v[meio])){
        bb(v,l,meio-1);
    } else if(less(v[meio],b)){
        bb(v,meio+1,r);
    }
}

int main(){
    int num_comandos;
    Item *vetor_comandos;
    scanf("%d", &num_comandos);
    vetor_comandos = (Item*) malloc(num_comandos*sizeof(Item));
    getchar();
    for(int i=0; i<num_comandos; i++){
        scanf("%d %[^\n]s", &vetor_comandos[i].valor, vetor_comandos[i].comando);
    }
    insertionSort(vetor_comandos, 0, num_comandos-1);
    while(scanf("%d", &b.valor) != EOF){
        bb(vetor_comandos, 0, num_comandos - 1);
    } 
}