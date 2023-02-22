#include <stdio.h>
#include <stdlib.h>

typedef struct no_st{
    int num;
    struct no_st *prox;
} No;

typedef struct cabeca_fil{
    No *inicio, *fim;
} Cabeca_Fila;

typedef struct cabeca_pil{
    No *inicio;
} Cabeca_Pilha;

int enfilar(Cabeca_Fila *h_f, int numero){
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return 0;
    novo->num = numero; 
    if(h_f->inicio == NULL){
        novo->prox = h_f->fim;
        h_f->fim = novo;
        h_f->inicio = novo;
        //printf("Numero inserido inicio: %d\n", h_f->inicio->num);
        return 1;
    }
    novo->prox = h_f->fim->prox;
    h_f->fim->prox = novo;
    h_f->fim = novo;
    //printf("Numero inserido inicio: %d\n", h_f->fim->num);
    return 1;
}

int espia(Cabeca_Fila *h_f){
    if(h_f->inicio == NULL) return -1;
    return h_f->inicio->num;
}

int desenfilar(Cabeca_Fila *h_f){
    No *remover = malloc(sizeof(No));
    if(h_f->inicio != NULL){
        remover = h_f->inicio;
        h_f->inicio = remover->prox;
        free(remover);
        return 1;
    }
    return 0;
}

int empilhar(Cabeca_Pilha *h_p, int numero){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->num = numero;
    novo->prox = h_p->inicio;
    h_p->inicio = novo;
}

int topo(Cabeca_Pilha *h_p){
    if(h_p->inicio == NULL) return -1;
    return h_p->inicio->num;
}

int desempilhar(Cabeca_Pilha *h_p){
    No *removido = malloc(sizeof(No));
    removido = h_p->inicio;
    if(removido != NULL){
        h_p->inicio = removido->prox;
        free(removido);
        return 1;       
    }
    return 0;
}

/*
int main(){
    int n, caminhao, aux, num_cam, errado;
    Cabeca_Fila *fila_viela, *fila;
    Cabeca_Pilha *pilha_aux;
    while(scanf("%d", &n)){
        errado = 0;
        if(n == 0) break;
        fila = malloc(sizeof(Cabeca_Fila));
        pilha_aux = malloc(sizeof(Cabeca_Pilha));
        fila_viela = malloc(sizeof(Cabeca_Fila));
        fila->inicio = NULL;
        fila->fim = NULL;
        pilha_aux->inicio = NULL;
        fila_viela->inicio = NULL;
        fila_viela->fim = NULL;
        for(int i = 0; i<n; i++){
            scanf("%d", &caminhao);
            enfilar(fila, caminhao);
        }
        aux = 1;
        for(int i = 0; i < n; i++){
            num_cam = espia(fila);
            printf("Fila inicial: %d\n", num_cam); 
            if(num_cam!=-1){
                if(num_cam == aux){ 
                    //printf("Aqui 1!\n");
                    empilhar(pilha_aux, num_cam);
                    aux++;
                } else {
                    printf("Fila viela: %d!\n", espia(fila_viela));
                    while(espia(fila_viela) == aux){
                        empilhar(pilha_aux, espia(fila_viela));
                        desenfilar(fila_viela);
                        aux++;
                    }
                    if(espia(fila_viela) == -1){
                        fila_viela = malloc(sizeof(Cabeca_Fila));
                        fila_viela->inicio = NULL;
                        fila_viela->fim = NULL;
                    }
                    enfilar(fila_viela, num_cam);
                }
                desenfilar(fila);
            }
        }
        aux = n;
        
        while(espia(fila_viela) != -1){
            num_cam = espia(fila_viela);
            printf("Elemento fila viela: %d\n", num_cam);
            desenfilar(fila_viela);
        }
    
        while(topo(pilha_aux) != -1){
            num_cam = topo(pilha_aux);
            printf("Elemento pilha: %d\n", num_cam);
            desempilhar(pilha_aux);
        } 
        /*
        while(espia(fila_viela) != -1){
            num_cam = espia(fila_viela);
            printf("Elemento pilha viela: %d\n", num_cam);
            if(aux != num_cam){
                errado = 1;
                //printf("Aqui\n");
                break;
            }
            aux--;
            desenfilar(fila_viela);
        }
        if(!errado){
            while(topo(pilha_aux) != -1){
                num_cam = topo(pilha_aux);
                printf("Elemento pilha: %d\n", num_cam);
                if(aux != num_cam){
                    errado = 1;
                    break;
                }
                aux--;
                desempilhar(pilha_aux);
            }    
        }
        if(errado){
            printf("no\n");
        } else {
            printf("yes\n");
        }*/
    /*
5
4 1 5 3 2
no
5
3 1 2 5 4
yes
5
5 3 2 1 4 - X
yes
10
1 2 10 5 4 3 7 6 8 9 - X
yes
10
1 2 10 5 4 3 9 8 7 6 - 
yes
5
3 5 2 4 1
no
5
1 2 4 3 5
yes
4
4 2 3 1
no
*/


int main(){
    int n, caminhao, aux, num_cam, errado;
    Cabeca_Fila *fila;
    Cabeca_Pilha *pilha_aux, *pilha_viela;
    while(scanf("%d", &n)){
        errado = 0;
        if(n == 0) break;
        fila = malloc(sizeof(Cabeca_Fila));
        pilha_aux = malloc(sizeof(Cabeca_Pilha));
        pilha_viela = malloc(sizeof(Cabeca_Pilha));
        fila->inicio = NULL;
        fila->fim = NULL;
        pilha_aux->inicio = NULL;
        pilha_viela->inicio = NULL;
        for(int i = 0; i<n; i++){
            scanf("%d", &caminhao);
            enfilar(fila, caminhao);
        }
        aux = 1;
        for(int i = 0; i < n; i++){
            num_cam = espia(fila);
            //printf("Fila inicial: %d\n", num_cam); 
            if(num_cam!=-1){
                if(num_cam == aux){ 
                    //printf("Aqui 1!\n");
                    empilhar(pilha_aux, num_cam);
                    aux++;
                } else {
                    //printf("Fila viela: %d!\n", espia(fila_viela));
                    while(topo(pilha_viela) == aux){
                        //printf("Entrou aquiiiiiiiiiiiiiii\n");
                        empilhar(pilha_aux, topo(pilha_viela));
                        desempilhar(pilha_viela);
                        aux++;
                    }
                    if(topo(pilha_viela) == -1){
                        pilha_viela = malloc(sizeof(Cabeca_Fila));
                        pilha_viela->inicio = NULL;
                    }
                    empilhar(pilha_viela, num_cam);
                }
                desenfilar(fila);
            }
        }

        while(topo(pilha_viela) != -1){
            num_cam = topo(pilha_viela);
            desempilhar(pilha_viela);
            empilhar(pilha_aux, num_cam);
        }
        aux = n;
        while(topo(pilha_aux) != -1){
            num_cam = topo(pilha_aux);
            if(num_cam != aux){
                errado = 1;
                break;
            }
            desempilhar(pilha_aux);
            aux--;
        }
        if(errado){
            printf("no\n");
        } else {
            printf("yes\n");
        }
        /*
        while(espia(fila_viela) != -1){
            num_cam = espia(fila_viela);
            printf("Elemento pilha viela: %d\n", num_cam);
            if(aux != num_cam){
                errado = 1;
                //printf("Aqui\n");
                break;
            }
            aux--;
            desenfilar(fila_viela);
        }
        if(!errado){
            while(topo(pilha_aux) != -1){
                num_cam = topo(pilha_aux);
                printf("Elemento pilha: %d\n", num_cam);
                if(aux != num_cam){
                    errado = 1;
                    break;
                }
                aux--;
                desempilhar(pilha_aux);
            }    
        }
        if(errado){
            printf("no\n");
        } else {
            printf("yes\n");
        }
        /*
        while(espia(fila_viela) != -1){
            num_cam = espia(fila_viela);
            printf("Elemento pilha viela: %d\n", num_cam);
            if(aux != num_cam){
                errado = 1;
                //printf("Aqui\n");
                break;
            }
            aux--;
            desenfilar(fila_viela);
        }
        if(!errado){
            while(topo(pilha_aux) != -1){
                num_cam = topo(pilha_aux);
                printf("Elemento pilha: %d\n", num_cam);
                if(aux != num_cam){
                    errado = 1;
                    break;
                }
                aux--;
                desempilhar(pilha_aux);
            }    
        }
        if(errado){
            printf("no\n");
        } else {
            printf("yes\n");
        }*/
    }
    return 0;
    /*
5
4 1 5 3 2
no
5
3 1 2 5 4
yes
5
5 3 2 1 4 - X
yes
10
1 2 10 5 4 3 7 6 8 9 - X
yes
10
1 2 10 5 4 3 9 8 7 6 - 
yes
5
3 5 2 4 1
no
5
1 2 4 3 5
yes
4
4 2 3 1
no
*/
}