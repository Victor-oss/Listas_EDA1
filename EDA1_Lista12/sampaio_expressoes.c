#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TIPO_PILHA char
#define boolean int

struct Pilha {
    int posicao_topo; /* posiÃ§Ã£o elemento posicao_topo */
    int capacidade;
    TIPO_PILHA *vetor;
} typedef Pilha;

boolean criarpilha(struct Pilha *p, int capacidade) {
    p->posicao_topo = -1;
    p->capacidade = capacidade;
    p->vetor = (TIPO_PILHA *)malloc(capacidade * sizeof(TIPO_PILHA));

    if(p->vetor == NULL)
        return FALSE;
    else
        return TRUE;
}

boolean estavazia(struct Pilha *p) {
    if (p->posicao_topo == -1)
        return TRUE; // vazia
    else
        return FALSE; // contém algo
}

boolean estacheia(struct Pilha *p) {
    if (p->posicao_topo == p->capacidade - 1)
        return TRUE; // cheia
    else
        return FALSE; // pode colocar
}

boolean empilhar(struct Pilha *p, TIPO_PILHA v) {
    if (estacheia(p) == TRUE) // verifica se esta existe espaço
        return FALSE;

    p->posicao_topo++;
    p->vetor[p->posicao_topo] = v;

    return TRUE;
}

boolean desempilhar(struct Pilha *p) {
    if (estavazia(p) == TRUE)
        return FALSE;

    p->posicao_topo--;

    return TRUE;
}

TIPO_PILHA retornaposicao_topo(struct Pilha *p) {
    return p->vetor[p->posicao_topo];
}

int main() {

    Pilha pilha;
    int capacidade;
    char palavra[100000];

    int instancias = 0;

    scanf("%d ", &instancias);

    for(int i = 0; i<instancias; i++){

        scanf("%s%n", palavra, &capacidade);

        getchar();

        if(capacidade % 2 != 0) {
          printf("N\n");
          goto fim;
        }

        criarpilha(&pilha, capacidade);
      
        for(int i = 0; palavra[i]!='\0'; i++) {

            if(palavra[i]=='{' || palavra[i]=='[' || palavra[i]=='('){
                empilhar(&pilha, palavra[i]);
            }

            if(palavra[i]=='}' || palavra[i]==']' || palavra[i]==')'){
                char topo = retornaposicao_topo(&pilha);

                if(topo=='{' && palavra[i]=='}'){
                    desempilhar(&pilha);
                } else if(topo=='[' && palavra[i]==']') {
                    desempilhar(&pilha);
                } else if(topo=='(' && palavra[i]==')') {
                    desempilhar(&pilha);
                } else if(estavazia(&pilha) == TRUE && (palavra[i]==')' || palavra[i]==']' || palavra[i]=='}')){
                  printf("N\n");
                  goto fim;
                }
            }//(){)}
        }

        if(estavazia(&pilha) == TRUE) {
            printf("S\n");
        } else {
            printf("N\n");
        }
      
      fim:;
    }

    return 0;
}
