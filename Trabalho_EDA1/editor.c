#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_st{
    struct no_st *prox;
    char frase[101];
};

struct cabeca_st{
    struct no_st *inicio;
};

int empilhar(struct cabeca_st *h, char *item){
    struct no_st *novo = malloc(sizeof(struct no_st));
    if(novo == NULL) return 0;
    novo->prox = malloc(sizeof(struct no_st));
    if(novo->prox == NULL) return 0;
    strcpy(novo->frase, item);
    novo->prox = h->inicio;
    h->inicio = novo;
    return 1;
}

void desempilhar(struct cabeca_st *h){    
    struct no_st *removido = h->inicio;
    if(removido == NULL){
       printf("NULL\n");
       return;
    } else {
        printf("%s\n", removido->frase);
    }
    h->inicio = h->inicio->prox;
    free(removido);
}

int main(){
    struct cabeca_st *cab_pilha = malloc(sizeof(struct cabeca_st));
    cab_pilha->inicio = NULL;
    char linha[110];
    while(scanf("%[^\n]s", linha)!=EOF){
        getchar();
        if(linha[6] == 'r'){ //inserir
            empilhar(cab_pilha, (linha+8));
        } else { //desfazer
            desempilhar(cab_pilha);
        }
    }
}

