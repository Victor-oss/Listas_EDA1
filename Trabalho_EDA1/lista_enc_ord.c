#include <stdio.h>
#include <stdlib.h>

typedef struct no_st{
    int numero;
    struct no_st *prox, *ant;
} No;

typedef struct cabeca_st{
    No *inicio;
} Cabeca;

int inserir_inicio_antes_fim(Cabeca *h, int num){
    No *novo = malloc(sizeof(No)), *aux;
    if(novo == NULL) return 0;
    novo->numero = num;
    if(h->inicio == NULL){
        h->inicio = novo;
        novo->ant = NULL;
        novo->prox = NULL;
        return 1;
    }
    aux = h->inicio;
    while(aux->prox != NULL && num > aux->numero){//so e menor q o ultimo elemento
        aux = aux->prox;
    }
    if(aux->prox == NULL){
        if(num > aux->numero){//e o maior
            novo->prox = NULL;
            novo->ant = aux;
            aux->prox = novo;
            return 1;
        } 
    }
    novo->prox = aux;
    if(aux == h->inicio){//E menor que o inicio
        novo->ant = NULL;
        aux->ant = novo;
        h->inicio = novo;
    } else {
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
    }
    return 1;
}

/*
  int a, b, c;

  while (fscanf(file, "%d%d%d", &a, &b, &c) != EOF) {
    printf("Read values: %d %d %d\n", a, b, c);
  }

  fclose(file);
*/

int main(){
    FILE *file;
    Cabeca *cabeca_placas;
    No *placa;
    cabeca_placas = malloc(sizeof(Cabeca));
    cabeca_placas->inicio = NULL;
    int o, n_placas, cont;
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

   while(fscanf(file, "%d %d", &o, &n_placas) != EOF){
        switch (o){
            case 1:
                inserir_inicio_antes_fim(cabeca_placas, n_placas);
                break;
            default:
                cont = 0;
                placa = cabeca_placas->inicio;
                while(placa != NULL && cont < n_placas - 1){
                    printf("%d ", placa->numero);
                    placa = placa->prox;
                    cont ++;
                }
                if(placa != NULL) printf("%d\n", placa->numero);
                break;
        }
    }
    return 0;
}