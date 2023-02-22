#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A < B)

#define exch(A,B) { Item tt = A; \
                    A = B; \
                    B = tt; \
}

#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

typedef int Item;

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
    return;
}

int separa(Item *v, int l, int r){
    int i = l-1, j = r;
    Item p = v[r];
    for(;;){
        while(less(v[++i], p));
        while(less(p, v[--j])) if(j == l) break;
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSortM3(Item *v, int l, int r){
    if((r - l) <= 16) return insertionSort(v, l, r);
    int med = (r-l)/2 + l;
    exch(v[med], v[r-1]);
    cmpexch(v[r], v[l]);
    cmpexch(v[r-1], v[l]);
    cmpexch(v[r], v[r-1]);
    int j = separa(v, l, r);
    quickSortM3(v, l, j-1);
    quickSortM3(v, j+1, r);
}

Item placas[10000001];

int main(){
    int o, n_placas, cont, ind_vetor = 0;
    while(scanf("%d", &o) != EOF){
        switch (o){
            case 1:
                scanf("%d", &placas[ind_vetor++]);
                break;
            default:
                quickSortM3(placas, 0, ind_vetor-1);
                cont = 0;
                scanf("%d", &n_placas);
                while(cont < n_placas - 1){
                    printf("%d ", placas[cont]);
                    cont ++;
                }
                printf("%d\n", placas[cont]);
                break;
        }
    }
    return 0;
}


/*
int main(){
    FILE *file;
    int o, n_placas, cont, ind_vetor = 0;
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    while(fscanf(file, "%d %d", &o, &n_placas) != EOF){
        switch (o){
            case 1:
                placas[ind_vetor++] = n_placas;
                break;
            default:
                quickSortM3(placas, 0, ind_vetor-1);
                cont = 0;
                while(cont < n_placas - 1){
                    printf("%d ", placas[cont]);
                    cont ++;
                }
                printf("%d\n", placas[cont]);
                break;
        }
    }
    return 0;
}*/