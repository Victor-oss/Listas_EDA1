#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char valor; //sublinhado = s, negrito = n, italico = i
    struct no *prox;
} No;

typedef struct cabeca_st{
    No *inicio;
} Cabeca;

int empilhar(Cabeca *h, char val){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return 0;
    novo->prox = malloc(sizeof(No));
    if(novo->prox == NULL) return 0;
    novo->prox = h->inicio;
    novo->valor = val;
    h->inicio = novo;
    return 1;
}

void desempilhar(struct cabeca_st *h){    
    No *removido = h->inicio;
    if(h->inicio == NULL) return;
    h->inicio = h->inicio->prox;
    free(removido);
}

char espia(Cabeca *h){
    if(h->inicio == NULL)
        return 0;
    else
        return h->inicio->valor;
}

char linha[100001];

int main(){
    int N, j;
    Cabeca *cab_pilha = malloc(sizeof(Cabeca));
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        j = 0; 
        scanf("%[^\n]s", linha);
        getchar();
        while(linha[j] != '\0'){
            if(linha[j] == '*'){
                if(espia(cab_pilha) == '*'){
                    desempilhar(cab_pilha);
                } else {
                    empilhar(cab_pilha, '*');
                }
            } else if(linha[j] == '_'){
                if(espia(cab_pilha) == '_'){
                    desempilhar(cab_pilha);
                } else {
                    empilhar(cab_pilha, '_');
                } 
            } else if (linha[j] == '/'){
                if(espia(cab_pilha) == '/'){
                    desempilhar(cab_pilha);
                } else {
                    empilhar(cab_pilha, '/');
                }
            }
            j++; 
        }
    }
    if(espia(cab_pilha) == 0){
        printf("C\n");
    } else {
        printf("E\n");
    }

/*
 for(int i = 0; i < T; i++){
        saiu = 1;
        scanf("%s%n", linha, &tam_linha);
        getchar();
        j = 0;
        if(tam_linha%2 == 0){
            if(inicializarPilha(pil, tam_linha)){
                while(linha[j] != '\0'){
                    if(linha[j] == '{' || linha[j] == '[' || linha[j] ==  '('){
                        empilha(pil, linha[j]);
                    } else if(linha[j] == '}' && topo(pil) == '{') {
                        desempilha(pil);
                    } else if(linha[j] == ']' && topo(pil) == '[') {
                        desempilha(pil); 
                    } else if(linha[j] == ')' && topo(pil) == '(') {
                        desempilha(pil);
                    } else if(p_esta_vazia(pil) && (linha[j]==')' || linha[j]==']' || linha[j]=='}')){
                        saiu = 0;
                        printf("N\n");
                        break;
                    }
                    j++;
                }
                if(saiu == 1){
                    if(p_esta_vazia(pil)){
                        printf("S\n");
                    } else {
                        printf("N\n");
                    }
                }
            }
        } else {
            printf("N\n");
        }
    }
*/

/*

*/

}



