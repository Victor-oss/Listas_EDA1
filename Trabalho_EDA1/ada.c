#include <stdio.h>
#include <stdlib.h>

typedef struct no_st {
    int numero;
    struct no_st *prox, *ant;
} Elemento;

typedef struct cabeca_st {
    Elemento *inicio, *fim;
} Cabeca_Lista;


void inicializar_lista(Cabeca_Lista *h){
    h->inicio = NULL;
    h->fim = NULL;
}


void inserirInicio(Cabeca_Lista *h, int novo_num){
    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL) return;
    if(h->inicio != NULL){
        h->inicio->ant = novo;    
    }
    if(h->fim == NULL){
        h->fim = novo;    
    }
    novo->numero = novo_num;
    novo->prox = h->inicio;
    novo->ant = NULL;
    h->inicio = novo;
}

void removerInicio(Cabeca_Lista *h){
    Elemento *removido;
    if(h->inicio == NULL){
        printf("No job for Ada?\n");
        return;
    }
    removido = h->inicio;
    if(h->inicio == h->fim){
        h->inicio = NULL;
        h->fim = NULL;
    } else {
        h->inicio = h->inicio->prox;
        h->inicio->ant = NULL;
    }
    printf("%d\n", removido->numero);
}

void inserirFim(Cabeca_Lista *h, int novo_num){
    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL) return;
    if(h->fim != NULL){
        h->fim->prox = novo;
    }
    if(h->inicio == NULL){
        h->inicio = novo;
    }
    novo->numero = novo_num;
    novo->prox = NULL; 
    novo->ant = h->fim;
    h->fim = novo;
}

void removerFim(Cabeca_Lista *h){
    Elemento *removido;
    if(h->fim == NULL){
        printf("No job for Ada?\n");
        return;
    }
    removido = h->fim;
    if(h->fim == h->inicio){
        h->fim = NULL;
        h->inicio = NULL;
    } else {
        h->fim = h->fim->ant;
        h->fim->prox = NULL;
    }
    printf("%d\n", removido->numero);
}

int main(){
    char comando[10];
    int Q = 0, N = 0, reverso = 0;
    scanf("%d", &Q);
    Cabeca_Lista cabeca; 
    inicializar_lista(&cabeca);
    for(int i = 0; i < Q;i++){
        scanf("%s", comando);
        if(comando[0] == 'b'){ //back
            if(reverso){
                removerInicio(&cabeca);
            } else {
                removerFim(&cabeca);
            }
        } else if(comando[0] == 'f'){ //front
            if(reverso){
                removerFim(&cabeca);
            } else {
                removerInicio(&cabeca);
            }
        } else if(comando[0] == 'r'){ //reverse
            reverso = !reverso;
        } else if(comando[0] == 'p'){ //push_back;
            scanf(" %d", &N);
            if(reverso){
                inserirInicio(&cabeca, N);
            } else {
                inserirFim(&cabeca, N);
            }
        } else { //toFront
            scanf(" %d", &N);
            if(reverso){
                inserirFim(&cabeca, N);
            } else {
                inserirInicio(&cabeca, N);
            }
        }
        getchar();
    }
    return 0;
}