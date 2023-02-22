#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct pilha_st {
    Item *v;
    int topo;
    int tamanho;
};

int inicializa_pilha(struct pilha_st *p, int tam){
    p->v = (Item*) malloc(sizeof(Item)*tam);
    if(p->v == NULL) return 0;
    p->tamanho = tam;
    p->topo = 0;
    return 1;
}

int empilha(struct pilha_st *p, Item a){
    if(p->topo == p->tamanho) return 0;
    p->v[p->topo++] = a;
    return 1;
}

Item topo(struct pilha_st *p){
    return p->v[p->topo - 1];
}

int pilha_esta_vazia(struct pilha_st *p){
    return p->topo == 0;
}

int desempilha(struct pilha_st *p){
    if(p->topo == 0) return 0;
    p->topo--;
    return 1;
}

struct fila_st{
    Item *v;
    int tamanho, ocupados;
    int ini, fim;
};

int inicializa_fila(struct fila_st *f, int tam){
    f->v = malloc(sizeof(Item)*tam);
    if(f->v == NULL) return 0;
    f->ocupados = 0;
    f->tamanho = tam;
    f->ini = -1;
    f->fim = 0;
    return 1;
}

int enfila(struct fila_st *f, Item a){
    if(f->fim == f->tamanho) return 0;
    f->v[f->fim] = a;
    f->fim = (f->fim + 1)%f->tamanho;
    f->ocupados++;
    return 1;
}

void desenfila(struct fila_st *f){
    f->ocupados--;
    f->ini = (f->ini+1)%f->tamanho;
}

int ocupados(struct fila_st *f){
    return f->ocupados;
}

Item espia(struct fila_st *f){
    return f->v[(f->ini + 1)%f->tamanho];
}

int fila_esta_vazia(struct fila_st *f){
    return f->ocupados == 0;
}

int main(){
    int n, num_termos, pt;
    Item carta;
    struct pilha_st *pilha_cartas;
    struct fila_st *fila_fundo, *fila_descartadas, *fila_aux;
    pilha_cartas = (struct pilha_st*) malloc(sizeof(struct pilha_st));
    fila_fundo = (struct fila_st*) malloc(sizeof(struct fila_st));
    fila_descartadas = (struct fila_st*) malloc(sizeof(struct fila_st));
    fila_aux = (struct fila_st*) malloc(sizeof(struct fila_st));
    scanf("%d", &n);
    inicializa_pilha(pilha_cartas, n);
    inicializa_fila(fila_descartadas, n-1);
    inicializa_fila(fila_fundo, n/2);
    for(int i = n; i >= 1; i--){
        empilha(pilha_cartas, i);
    }
    while(!pilha_esta_vazia(pilha_cartas)){
        carta = topo(pilha_cartas);
        desempilha(pilha_cartas);
        enfila(fila_descartadas, carta);
        if(pilha_esta_vazia(pilha_cartas)){
            pt = 1;
            break;
        } else {
            carta = topo(pilha_cartas);
            desempilha(pilha_cartas);
            enfila(fila_fundo, carta);
            pt = 2;
        }
    }
    free(pilha_cartas);
    num_termos = ocupados(fila_fundo);
    while(ocupados(fila_fundo) > 1){
        if(num_termos%2 == 1 && pt == 1){
            num_termos = (num_termos+1)/2;
        } else {
            num_termos = (num_termos)/2;
        }
        inicializa_fila(fila_aux, num_termos);
        while(!fila_esta_vazia(fila_fundo)){
            if(pt == 2){
                carta = espia(fila_fundo);
                desenfila(fila_fundo);
                enfila(fila_descartadas, carta);
                pt = 1;
            } else {
                carta = espia(fila_fundo);
                desenfila(fila_fundo);
                enfila(fila_aux, carta);
                pt = 2;
            }
        }    
        *fila_fundo = *fila_aux;
    }   
    desenfila(fila_fundo);
    printf("Cartas descartadas:");
    int num_descartados = ocupados(fila_descartadas); 
    while(ocupados(fila_descartadas) > 1){
        carta = espia(fila_descartadas);
        printf(" %d,", carta);
        desenfila(fila_descartadas);       
    }
    carta = espia(fila_descartadas);
    printf(" %d\n", carta);
    free(fila_descartadas);
    printf("Carta restante: ");
    carta = espia(fila_fundo);
    printf("%d\n", espia(fila_fundo));
    free(fila_fundo);
}