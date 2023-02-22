#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int b;

void merge(int *v, int l, int r1, int r2){
    int i = l, j = r1+1, k = 0, fim1 = 0, fim2 = 0, tamanho;
    tamanho = r2 - l + 1;
    int *v2 = (int*) malloc(sizeof(int) * tamanho);
    if(v2 != NULL){
        for(; k < tamanho; k++){
            if(!fim1 && !fim2){
                if(v[i] < v[j])
                    v2[k] = v[i++];
                else 
                    v2[k] = v[j++];
                
                if(i > r1) fim1 = 1;
                if(j > r2) fim2 = 1;
            } else {
                if(!fim1) 
                    v2[k] = v[i++];
                if(!fim2) 
                    v2[k] = v[j++];
            }
        }
        for(i = l, k = 0; k < tamanho; i++, k++){
            v[i] = v2[k];
        }
    }

    free(v2);
}

void mergeSort(int *v, int l, int r){
    int meio;
    if(l < r){
        meio = (r-l)/2 + l;
        mergeSort(v, l, meio);
        mergeSort(v, meio+1, r);
        merge(v, l, meio, r);
    }
}

int busca_binaria(int *v, int n){
    int i, inicio = 0, meio, final = n-1;
    while(inicio <= final){
        meio = inicio + (final - inicio)/2;
        if(b < v[meio]){
            final = meio - 1;
        } else if(v[meio] < b){
            inicio = meio + 1;
        } else {
            return meio;
        } 
    } 
    return -1;
}

int main(){
    int n;
    int vetor[140000];
    scanf("%d", &n);
    for(int a = 0; a < n; a++){
        scanf("%d", &vetor[a]);               
    }
    mergeSort(vetor, 0, n - 1);
    while(scanf("%d", &b) != EOF){
        if(busca_binaria(vetor, n) != -1){
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
    return 0;
}