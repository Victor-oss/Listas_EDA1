#include <stdio.h>
#include <stdlib.h>

typedef struct no_st{
    int linha, coluna;
    struct no_st *prox;
    int tamanho;
} Torre;

typedef struct cabeca_fila{
    Torre *inicio, *fim;
} Cabeca_Fila;

int enfilar(Cabeca_Fila *h_f, int nova_linha, int novo_coluna, int tam){
    Torre *novo = malloc(sizeof(Torre));
    if(novo == NULL) return 0;
    novo->linha = nova_linha;
    novo->coluna = novo_coluna;
    novo->tamanho = tam;
    if(h_f->inicio == NULL){
        h_f->inicio = novo;
        h_f->fim = novo;
    } else {
        h_f->fim->prox = novo;
        h_f->fim = novo;        
    }
    return 1;
}

Torre* espia(Cabeca_Fila *h_f){
    return h_f->inicio;
}

int desenfilar(Cabeca_Fila *h_f){
    Torre *remover = malloc(sizeof(Torre));
    if(remover == NULL) return 0;
    if(h_f->inicio != NULL){ 
        remover = h_f->inicio;
        h_f->inicio = h_f->inicio->prox;
        free(remover);
        return 1;
    }
    return 0;
}

int libera_area(char **tabuleiro, Torre *t, int n_linhas, int n_colunas){
   int liberados = 0, ind_linha, ind_coluna; 
    for(ind_linha = t->linha - t->tamanho; ind_linha <= t->linha + t->tamanho; ind_linha++){
        for(ind_coluna = t->coluna - t->tamanho; ind_coluna <= t->coluna + t->tamanho; ind_coluna++){
            if(ind_linha >= 0 && ind_coluna >= 0 && ind_linha < n_linhas && ind_coluna < n_colunas){
                if(tabuleiro[ind_linha][ind_coluna] == '#'){
                    tabuleiro[ind_linha][ind_coluna] = '.';
                    liberados++;
                }
            }
        }    
    }
    return liberados;
}

int main(){
    int N, M, cont_torres = 0, cont_visiveis = 0;
    Torre *visualizada;
    char **reserva;  
    Cabeca_Fila *fila_torres, *fila_aux;
    int tam_torre;
    scanf("%d %d", &N, &M);
    getchar();
    fila_torres = malloc(sizeof(Cabeca_Fila));
    fila_torres->fim = NULL;
    fila_torres->inicio = NULL;
    fila_aux = malloc(sizeof(Cabeca_Fila));
    fila_aux->fim = NULL;
    fila_aux->inicio = NULL;
    reserva = malloc(sizeof(char*)*N);    
    for(int linha = 0; linha < N; linha++){
        reserva[linha] = malloc(sizeof(char)*M); 
        for(int coluna = 0; coluna < M; coluna++){
            scanf("%c", &reserva[linha][coluna]);
            //printf("x = %d y = %d\n", i, j);
            if(reserva[linha][coluna] == 't'){ 
                cont_torres++;
                enfilar(fila_torres, linha, coluna, 0);
            }
        }
        getchar();
    }
    for(;cont_torres>0;cont_torres--){
        visualizada = espia(fila_torres);
        scanf("%d", &tam_torre);
        enfilar(fila_aux, visualizada->linha, visualizada->coluna, tam_torre);       
        desenfilar(fila_torres);      
    }
    free(fila_torres);
    while(espia(fila_aux) != NULL){
        visualizada = espia(fila_aux);
        //printf("torre x = %d y = %d\n", visualizada->linha, visualizada->y);  
        cont_visiveis += libera_area(reserva, visualizada, N, M);
        desenfilar(fila_aux);
    }
    free(fila_aux);
    printf("%d\n", cont_visiveis);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%c", reserva[i][j]);
        }
        printf("\n");
    }

    return 0;
}