#include <stdio.h>
#include <stdlib.h>

typedef int Item;


#define less(A,B) (A < B)

#define exch(A,B) { Item tt = A; \
                    A = B; \
                    B = tt; \
}

#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}


void insertionSort(Item *vetor, int l, int r){
    for(int i = r; i > l; i--){
        cmpexch(vetor[i], vetor[i-1]);
    }
    for(int i = l+2; i <= r; i++){
       int j = i;
       Item aux = vetor[j];
       while(less(aux, vetor[j-1])){
        vetor[j] = vetor[j-1]; 
        j--;
       } 
       vetor[j] = aux;
    }   
}

void imprimirVetor(Item *vetor){
    int num = 0;
    while(vetor[num+1] != '\0'){
        printf("%d ", vetor[num++]);
    }
    printf("%d\n", vetor[num]);
}

int main(){
    int num, a = 0;
    Item *vetor = (Item*) malloc(50000 * sizeof(Item));
    while(scanf("%d", &num) != EOF){
        vetor[a++] = num;        
    }
    vetor[a] = '\0'; 
    insertionSort(vetor, 0, a - 1);
    imprimirVetor(vetor);
    return 0;   
}