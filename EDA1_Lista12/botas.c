#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct fila_st {
    Item *v;
    int ocupados, tamanho;
    int ini, fim;
};

int inicializa_fila(struct fila_st *f, int tam){
    f->v = malloc(sizeof(Item)*tam);
    if(f->v == NULL) return 0;
    f->ocupados = 0;
    f->tamanho = tam;
    f->fim = 0;
    f->ini = -1;
    return 1;
}

int enfila(struct fila_st *f, Item a){
    if(f->fim == f->tamanho) return 0;
    f->v[f->fim] = a;
    f->fim = (f->fim + 1)%f->tamanho;
    f->ocupados++;
    return 1;
}

Item espia(struct fila_st *f){
    return f->v[(f->ini+1)%f->tamanho];
}

int desenfila(struct fila_st *f){
    f->ini = (f->ini+1)%f->tamanho;
    f->ocupados--;
    return 1;
}

int fila_esta_vazia(struct fila_st *f){
    return f->ocupados == 0;
}

struct pares{
    int qtd_vezes;
};

int main(){
    int N, M, qtd_pares;
    struct fila_st *fila = malloc(sizeof(struct fila_st));
    char lado;
    struct pares *vetor_sapatos_esq, *vetor_sapatos_dir;
    inicializa_fila(fila, 1000);
    while(scanf("%d", &N) != EOF){
        qtd_pares = 0;
        vetor_sapatos_esq = malloc(31*sizeof(struct pares));
        vetor_sapatos_dir = malloc(31*sizeof(struct pares));
        for(int j = 0; j < N; j++){
            scanf("%d %c", &M, &lado);
            getchar();
            if(lado == 'E'){
                vetor_sapatos_esq[M-30].qtd_vezes++;
            } else {
                vetor_sapatos_dir[M-30].qtd_vezes++;
            }
        }
        for(int i = 0; i < 31; i++){
            if((vetor_sapatos_dir+i)->qtd_vezes && (vetor_sapatos_esq+i)->qtd_vezes){
                int qtd_direito = (vetor_sapatos_dir+i)->qtd_vezes;
                int qtd_esquerdo = (vetor_sapatos_esq+i)->qtd_vezes;
                if(qtd_direito > qtd_esquerdo){
                    qtd_pares += qtd_esquerdo;
                } else if(qtd_esquerdo > qtd_direito){
                    qtd_pares += qtd_direito;
                } else {
                    qtd_pares += qtd_direito;
                }
            }
        }
        enfila(fila, qtd_pares);
    }
    free(vetor_sapatos_dir);
    free(vetor_sapatos_esq);
    while(!fila_esta_vazia(fila)){
        printf("%d\n", espia(fila));
        desenfila(fila);
    }
    free(fila);
}