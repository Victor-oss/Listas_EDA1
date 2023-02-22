#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_st{
    char palavra[4194305];    
    int tamanho;
    struct no_st *prox;
} Elemento;

typedef struct cabeca_st{
    Elemento *inicio, *fim;
} Cabeca_Fila;

typedef struct qtd_st{  
    int qtd_aparece;
    struct qtd_st *prox;
} Elemento_Qtd;

typedef struct cabeca_st_qtd{
    Elemento_Qtd *inicio, *fim;
} Cabeca_Fila_Qtd;

char linha[4194305];
int tam_palavra;


int enfilar(Cabeca_Fila *h, int tam){
    Elemento *novo = malloc(sizeof(Elemento));
    if(novo == NULL) return 0;
    novo->tamanho = tam;
    strcpy(novo->palavra, linha);
    novo->prox = NULL;
    if(h->inicio == NULL){
        h->inicio = novo;
        h->fim = novo;
        return 1;
    }
    h->fim->prox = novo;
    h->fim = novo;
    return 1;
}

int desenfilar(Cabeca_Fila *h){
    Elemento *removido;
    removido = h->inicio;
    if(removido != NULL){
        h->inicio = h->inicio->prox;
        free(removido);
        return 1;
    }
    return 0;
}

Elemento* espia(Cabeca_Fila *h){
    if(h->inicio == NULL) return NULL;
    return h->inicio;
}

int enfilar_qtd(Cabeca_Fila_Qtd *h, int qtd){
    Elemento_Qtd *novo = malloc(sizeof(Elemento_Qtd));
    if(novo == NULL) return 0;
    novo->qtd_aparece = qtd;
    novo->prox = NULL;
    if(h->inicio == NULL){
        h->inicio = novo;
        h->fim = novo;
        return 1;
    }
    h->fim->prox = novo;
    h->fim = novo;
    return 1;
}

int desenfilar_qtd(Cabeca_Fila_Qtd *h){
    Elemento_Qtd *removido;
    removido = h->inicio;
    if(removido != NULL){
        h->inicio = h->inicio->prox;
        free(removido);
        return 1;
    }
    return 0;
}

int espia_qtd(Cabeca_Fila_Qtd *h){
    if(h->inicio == NULL) return -1;
    return h->inicio->qtd_aparece;
}


int qtd_substring(char *acomparar, int tamanho){
    int cont_substrings = 0, indice = 0, ind_aux, val;
    if(tam_palavra > tamanho) return 0;
    while((indice + tam_palavra) <= tamanho){
        ind_aux = 0;
        val = 1;
        while(ind_aux < tam_palavra){
            if(linha[ind_aux] != acomparar[indice+ind_aux]){
                val = 0;
                break;
            }
            ind_aux++;
        }
        if(val){
            cont_substrings++;
        }
        indice++;
    }
    return cont_substrings;
}

int main(){
    tam_palavra;
    Cabeca_Fila *cabeca = malloc(sizeof(Cabeca_Fila));
    Elemento *verifica;
    Cabeca_Fila_Qtd *cabeca_qtds = malloc(sizeof(Cabeca_Fila_Qtd));
    cabeca->fim = NULL;
    cabeca->inicio = NULL;
    while(scanf("%s%n", linha, &tam_palavra) != EOF){
        enfilar(cabeca, tam_palavra);
        getchar();
    }
    while(espia(cabeca)->prox != NULL){
        verifica = espia(cabeca);
        //printf("%s\n", verifica->palavra);
        enfilar_qtd(cabeca_qtds, qtd_substring(verifica->palavra, verifica->tamanho));
        desenfilar(cabeca);
    }
    while(espia_qtd(cabeca_qtds) != -1){
        printf("%d\n", espia_qtd(cabeca_qtds));
        desenfilar_qtd(cabeca_qtds);
    }

}