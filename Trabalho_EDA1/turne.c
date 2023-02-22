#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_st{
    int tamanho;
    char nome[27];
    struct no_st *prox, *ant;
} Cidade;

typedef struct cabeca_fila_st{
    Cidade *inicio;
    Cidade *fim;
    int ocupados;
} Cabeca_Fila;

int inicializar_fila(Cabeca_Fila *h_f){
    h_f->fim = NULL;
    h_f->inicio = NULL;
    h_f->ocupados = 0;   
}

int enfilar(Cabeca_Fila *h_f, char *nome_cidade, int tam){
    Cidade *nova = malloc(sizeof(Cidade));
    if(nova == NULL) return 0;
    nova->tamanho = tam;
    strcpy(nova->nome, nome_cidade);
    nova->prox = NULL;
    if(h_f->inicio == NULL){
        h_f->inicio = nova;
        h_f->fim = nova;
        nova->ant = NULL;
    } else {
        h_f->fim->prox = nova;
        nova->ant = h_f->fim;
        h_f->fim = nova;
    }
    h_f->ocupados++;
    return 1;
}

Cidade* espia(Cabeca_Fila *h_f){
    return h_f->inicio;
}

int desenfilar(Cabeca_Fila *h_f){
    Cidade *remover = malloc(sizeof(Cidade));
    if(remover == NULL) return 0;
    if(h_f->inicio != NULL){ 
        h_f->ocupados--;
        remover = h_f->inicio;
        h_f->inicio = h_f->inicio->prox;
        if(h_f->inicio != NULL) h_f->inicio->ant = NULL;
        free(remover);
        return 1;
    }
    return 0;
}

int ocupados(Cabeca_Fila *h_f){
    return h_f->ocupados;
}

void move_para_fim(Cabeca_Fila *h_f, Cidade *analisada){
    if(analisada == h_f->fim) return;
    //reserva = analisada->prox;
    //printf("Reserva 1 = %s\n", reserva->nome);
    analisada->prox->ant = analisada->ant;
    analisada->ant->prox = analisada->prox;
    h_f->fim->prox = analisada;
    analisada->ant = h_f->fim;
    analisada->prox = NULL;
    h_f->fim = analisada;
    //*analisada = *reserva;
    //printf("Analisada 1 = %s\n", analisada->nome);
    //printf("Reserva 2 = %s\n", reserva->nome);
}

/*
typedef struct cabeca_pilha_st{
    Cidade *inicio;
} Cabeca_Pilha;

int empilhar(Cabeca_Pilha *h, char *item, int tam){
    Cidade *novo = malloc(sizeof(Cidade));
    if(novo == NULL) return 0;
    novo->tamanho = tam;
    strcpy(novo->nome, item);
    novo->prox = h->inicio;
    h->inicio = novo;
    return 1;
}

Cidade* topo(Cabeca_Pilha *h_p){
    return h_p->inicio;
}

int desempilhar(Cabeca_Pilha *h_p){
    Cidade *remover = malloc(sizeof(Cidade));
    if(remover == NULL) return 0;
    if(h_p->inicio != NULL){
        remover = h_p->inicio;
        h_p->inicio = h_p->inicio->prox;
        free(remover);
        return 1;
    }
    return 0;
}*/

int main(){
    char cidade[27], ultimo_car;
    int tamanho_palavra;
    Cidade *cid, *reserva;
    Cabeca_Fila *fila_cidades;
    fila_cidades = malloc(sizeof(Cabeca_Fila));
    inicializar_fila(fila_cidades);
    while(scanf("%s%n", cidade, &tamanho_palavra) != EOF){
        getchar();
        enfilar(fila_cidades, cidade, tamanho_palavra);
    }
    if(fila_cidades->inicio != NULL){
        cid = fila_cidades->inicio;
        ultimo_car = cid->nome[cid->tamanho - 1] - 32;
        cid = cid->prox;
        while(cid != fila_cidades->fim && cid !=NULL){
            reserva = cid->prox;
            if(cid->nome[0] == ultimo_car){
                move_para_fim(fila_cidades, cid);
                //printf("Cidade anterior: %s\n", cid->nome);
                cid = reserva;
                //printf("Cidade media: %s\n", cid->nome);
                if(cid != NULL){
                    ultimo_car = cid->nome[cid->tamanho - 1] - 32;
                    cid = cid->prox;
                    //printf("Nova cidade: %s\n", cid->nome);
                }
            } else {
                ultimo_car = cid->nome[cid->tamanho - 1] - 32;
                cid = cid->prox;
            }
        }
        while(espia(fila_cidades) != NULL){
            cid = espia(fila_cidades);
            printf("%s\n", cid->nome);
            desenfilar(fila_cidades);
            //printf("Aqui\n");
        }
    }
    free(fila_cidades);
    return 0;
}
