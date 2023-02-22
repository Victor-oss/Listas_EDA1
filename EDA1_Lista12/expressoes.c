#include <stdio.h>
#include <stdlib.h>

typedef char Item;

struct pilha_st{
    Item *v;
    int topo;
    int tamanho;
};

int inicializarPilha(struct pilha_st *p, int tam){
    p->v = (Item*)malloc(tam*sizeof(Item));
    if(p->v == NULL) return 0;
    p->topo = 0;
    p->tamanho = tam;
    return 1;
}

int empilha(struct pilha_st *p, Item a){
    if(p->topo == p->tamanho) return 0;
    p->v[p->topo++]=a;
    return 1;
}

Item topo(struct pilha_st *p){
    return p->v[(p->topo)-1];
}

void desempilha(struct pilha_st *p){
    if(p->topo > 0){
        p->topo--;
    }
}

int p_esta_vazia(struct pilha_st *p){
    return p->topo == 0;
}

int main(){
    char linha[100001];
    int T, j, res, tam_linha, saiu;
    struct pilha_st *pil;
    pil = (struct pilha_st*) malloc(sizeof(struct pilha_st));
    scanf("%d", &T);
    getchar();
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
}