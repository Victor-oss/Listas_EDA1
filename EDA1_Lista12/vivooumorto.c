#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct fila_st{
    Item *v;
    int ini, fim;
    int ocupados, tamanho;
};

int inicializa_fila(struct fila_st  *f, int tam){
    f->v = malloc(sizeof(Item)*tam);
    if(f->v == NULL) return 0;
    f->fim = 0;
    f->ini = -1;
    f->ocupados = 0;
    f->tamanho = tam; 
    return 1;
}

int enfila(struct fila_st *f, Item a){
    if(f->fim == f->tamanho) return 0;
    f->ocupados++;
    f->v[f->fim] = a;
    f->fim = (f->fim + 1)%f->tamanho;
    return 1;
}

Item espia(struct fila_st *f){
    return f->v[(f->ini+1)%f->tamanho];
}

int desenfila(struct fila_st *f){
    f->ini = (f->ini + 1)%f->tamanho;
    f->ocupados--;
    return 1;
}

int fila_esta_vazia(struct fila_st *f){
    return f->ocupados == 0;
}

int main(){
    struct fila_st *fila_part, *fila_aux, *fila_ganhadores;
    int z;
    int acao, acao_mestre, participante, num_passaram, ind_part, P,R;
    fila_part = malloc(sizeof(struct fila_st));
    fila_aux = malloc(sizeof(struct fila_st));
    fila_ganhadores = malloc(sizeof(struct fila_st));
    inicializa_fila(fila_ganhadores, 1000);
    while(scanf("%d %d", &P, &R) == 2){
        if(P == 0 && R == 0){
            break;
        }
        inicializa_fila(fila_part, P);
        for(int a = 0; a < P; a++){
            scanf("%d", &ind_part);
            enfila(fila_part, ind_part);
        }
        num_passaram = P;
        for(int i = 0; i < R; i++){
            inicializa_fila(fila_aux, P);
            scanf("%d", &P);
            scanf("%d", &acao_mestre);
            for(int j = 0; j < num_passaram; j++){
                scanf("%d", &acao);
                if(acao == acao_mestre){
                    participante = espia(fila_part); 
                    enfila(fila_aux, participante);
                } 
                desenfila(fila_part);
            }
            *fila_part = *fila_aux;
            num_passaram = fila_part->ocupados;
        }
        ind_part = espia(fila_part);
        enfila(fila_ganhadores, ind_part);
    }
    z = 1;
    while(!fila_esta_vazia(fila_ganhadores)){
        printf("Teste %d\n", z);
        ind_part = espia(fila_ganhadores);
        printf("%d\n", ind_part);
        desenfila(fila_ganhadores);
        z++;
    }
}