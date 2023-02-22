#include <stdio.h>
#include <stdlib.h>

typedef struct pista{
    int identificador, valor, id_proximo;
    struct pista *prox;
} Pista;

typedef struct pista_inicial{
    int valor, id;
} Pistas_Inicial;

typedef struct cabeca{
    Pista *inicio;
} Cabeca_Lista;

/*int inserir_inicio(Cabeca_Lista *h, int id, int val, int prox){
    Pista *pista_novo = malloc(sizeof(Pista));
    if(pista_novo == NULL) return 0;
    pista_novo->identificador = id;
    pista_novo->valor = val;
    pista_novo->id_proximo = prox;
    pista_novo->prox = h->inicio;
    h->inicio = pista_novo;
    return 1;
}*/

int empilhar(Cabeca_Lista *h, int id, int val, int prox){
    Pista *nova = malloc(sizeof(Pista));
    if(nova == NULL) return 0;
    nova->prox = malloc(sizeof(Pista));
    if(nova->prox == NULL) return 0;
    nova->id_proximo = prox;
    nova->valor = val;
    nova->identificador = id;
    nova->prox = h->inicio;
    h->inicio = nova;
    return 1;
}


/*int inserir(Cabeca_Lista *h, int id, int val, int prox){
    if(h->inicio == NULL) return inserir_inicio(h, id, val, prox);
    if(h->inicio->identificador == prox) return inserir_inicio(h, id, val, prox);
    Pista *pista_novo = malloc(sizeof(Pista));
    Pista *aux = h->inicio;
    if(pista_novo == NULL) return 0;
    pista_novo->identificador = id;
    pista_novo->valor = val;
    pista_novo->id_proximo = prox;
    while(aux->prox != NULL){
        if(aux->prox->identificador == prox){
            break;
        } else {
            aux = aux->prox;
        }
    }   
    pista_novo->prox = aux->prox;
    aux->prox = pista_novo;
    return 1;
}*/

void imprime_lista(Cabeca_Lista *h){
    Pista *aux = h->inicio;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

Pistas_Inicial pistas[5001];

int main(){
    int n, id, valor, id_prox, id_ultimo, j = 0;
    Cabeca_Lista *cab_lista;
    cab_lista = malloc(sizeof(Cabeca_Lista));
    cab_lista->inicio = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &id, &valor, &id_prox);
        pistas[id_prox+1].id = id;
        pistas[id_prox+1].valor = valor;
    }
    for(int i = 0; i < n; i++){
        empilhar(cab_lista, pistas[j].id, pistas[j].valor, j-1);    
        j = pistas[j].id + 1;
    }
    imprime_lista(cab_lista);   
    return 0;
}