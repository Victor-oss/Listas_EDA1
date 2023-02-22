#include <stdio.h>
#include <stdlib.h>

typedef int Item;

Item b;

#define less(A,B) (A < B)

#define eq(A,B) (A == B)

/*void merge(Item *v, int l, int r1, int r2){
    Item *v2 = (Item*) malloc(sizeof(Item) * (r2 - l + 1));
    int i = l, j = r1+1, k = 0;
    while(i <= r1 && j <= r2){
        if(less(v[i], v[k])){
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
    if(l>=r) return;
    int meio = l + (r-l)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}*/

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

int bb(Item *v, int l, int r){
    int meio = l + (r-l)/2;
    if(l >= r){
        if(eq(v[meio], b)){
            return meio;        
        }
        return -1;
    }
    if(eq(v[meio], b)){
        return meio;        
    }
    if(less(v[meio], b)){
        return bb(v, meio+1, r);
    } else if(b, v[meio]){
        return bb(v, l, meio-1);
    }
}

int main(){
    int N, novoi = 0, novor, soma;
    Item *v;
    v = (Item*) malloc(sizeof(Item)*200000);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }
    mergeSort(v, 0, N-1);
    for(int i = 1; i < N; i++){
        if(v[i] != v[novoi]){
            v[++novoi] = v[i];
        }
    }
    novor = novoi;
    if(novor%2 == 0) v[++novor] = 1000000000;
    novoi = novor;
    for(int i = 0; i < novor; i+=2){
        b = v[i] + v[i+1];
        if(bb(v, 0, novor) == -1){
            v[++novoi] = b;            
        }
    }
    novor = novoi;
    mergeSort(v, 0, novor);
    for(int i = 0; i <= novor; i +=4){
        printf("%d\n", v[i]);
    }
    printf("Elementos: %d\n", novor + 1);
}