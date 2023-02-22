#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{char pala_jap[81]; char pala_port[81];} Item;

#define less(A,B) (strcmp(A.pala_jap, B.pala_jap) < 0)

#define equals(A,B) (strcmp(A.pala_jap, B.pala_jap) == 0)

#define exch(A,B) {Item tt = A;\
                   A = B;\
                   B = tt;}

#define cmpexch(A,B) {if(less(A,B)) exch(A,B);}

Item b;

int separa(Item *v, int l, int r){
    int i = l - 1, j = r;
    Item p = v[r];
    for(;;){
        while(less(v[++i], p));
        while(less(p, v[--j])) if(j == l) break;
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void qsM3(Item *v, int l, int r){
    if(l >= r) return;
    int meio = (r - l)/2 + l;
    exch(v[meio], v[r-1]);
    cmpexch(v[r], v[l]);
    cmpexch(v[r-1], v[l]);
    cmpexch(v[r], v[r-1]);
    int j = separa(v, l, r);
    qsM3(v, l, j-1);
    qsM3(v, j+1, r);
}

int bb(Item *v, int l, int r){
    if(l > r) return -1;
    int meio = (r-l)/2 + l;
    if(equals(v[meio], b)){
        return meio;
    } else if(less(v[meio], b)){
        //printf("palavra jap: %s\n", v[meio].pala_jap);
        return bb(v, meio + 1, r);
    } else if(less(b, v[meio])){
        //printf("palavra jap: %s\n", v[meio].pala_jap);
        return bb(v, l, meio - 1);
    }
}

int main(){
    Item *vetor = (Item*)malloc(sizeof(Item));
    int t, m, n, k, j, tam_lin, ind;
    char auxiliar[81], linha[81];
    scanf("%d", &t);
    for(int v = 0; v < t; v++){
        scanf("%d", &m);
        vetor = (Item*) realloc(vetor, m*sizeof(Item));
        scanf("%d", &n);
        for(int i = 0; i < m; i++){
            getchar();
            scanf("%[^\n]s", vetor[i].pala_jap);
            getchar();
            scanf("%[^\n]s", vetor[i].pala_port);
        }
        qsM3(vetor, 0, m-1);
        for(int i = 0; i  < n; i++){
            getchar();
            scanf("%[^\n]s%n", linha, &tam_lin);
            k = 0;
            j = 0;
            while(linha[k] != '\0'){
                if(linha[k] == ' '){
                    auxiliar[j] = '\0';
                    j = 0;
                    strcpy(b.pala_jap, auxiliar);
                    ind = bb(vetor, 0, m-1);
                    if(ind == -1){
                        printf("%s ", auxiliar);
                    } else {
                        printf("%s ", vetor[ind].pala_port);
                    }
                } else if(linha[k+1] == '\0'){
                    auxiliar[j] = linha[k];
                    j++;
                    auxiliar[j] = '\0';
                    j = 0;
                    strcpy(b.pala_jap, auxiliar);
                    ind = bb(vetor, 0, m-1);
                    if(ind == -1){
                        printf("%s\n", auxiliar);
                    } else {
                        printf("%s\n", vetor[ind].pala_port);
                    }
                } else {
                    auxiliar[j] = linha[k];
                    j++;
                }
                k++;
            }
        }
    }
    return 0;
}