#include <stdio.h>
#include <stdlib.h>

typedef struct {int codigo; int n_votos;} Item;

#define less(A,B) (A.n_votos < B.n_votos || (A.n_votos == B.n_votos && A.codigo < B.codigo))

#define cmpexch_votos(A,B) {if(less(A,B)) exch(A,B);}

#define exch(A,B) {Item tt = A;\
                   A = B;\
                   B = tt;}

int separa_votos(Item *v, int l, int r){
    Item p = v[r];
    int j = l;
    for (int k = l; k < r; k++){
        if (less(v[k], p))
        {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void qs_votos_M3(Item *v, int l, int r){
    if(r <= l) return;
    int med = (r-l)/2 + l;
    exch(v[r-1], v[med]);
    cmpexch_votos(v[r], v[l]);
    cmpexch_votos(v[r-1], v[l]);
    cmpexch_votos(v[r], v[r-1]);
    int j = separa_votos(v, l, r);
    qs_votos_M3(v, l, j-1);
    qs_votos_M3(v, j+1, r);
}

Item vetor_p[91], vetor_sen[901], vetor_dep_fed[9001], vetor_dep_est[90001];

int main(){
    long long n_sen, n_dep_fed, n_dep_est; 
    int aux, cont_val = 0, cont_inval = 0;
    int cont_ps = 0, cont_sen = 0, cont_dep_fed = 0, cont_dep_est = 0;
    int cont_pres = 0;
    scanf("%lld %lld %lld", &n_sen, &n_dep_fed, &n_dep_est);
    while(scanf("%d", &aux) != EOF){
        if(aux > 0){
            if(aux < 100){
                vetor_p[aux-10].codigo = aux;
                vetor_p[aux-10].n_votos++;      
                cont_pres++;
            } else if(aux < 1000){
                vetor_sen[aux-100].codigo = aux;
                vetor_sen[aux-100].n_votos++;                                
            } else if(aux < 10000){
                vetor_dep_fed[aux-1000].codigo = aux;
                vetor_dep_fed[aux-1000].n_votos++;                      
            } else {
                vetor_dep_est[aux-10000].codigo = aux;
                vetor_dep_est[aux-10000].n_votos++;             
            }
            cont_val++;
        } else {
            cont_inval++;
        }
    }

    for (int i = 0; i < 91; i++){
        if (vetor_p[i].codigo) vetor_p[cont_ps++] = vetor_p[i];
    }
    for (int i = 0; i < 901; i++){
        if (vetor_sen[i].codigo) vetor_sen[cont_sen++] = vetor_sen[i];
    }
    for (int i = 0; i < 9001; i++){
        if (vetor_dep_fed[i].codigo) vetor_dep_fed[cont_dep_fed++] = vetor_dep_fed[i];
    }
    for (int i = 0; i < 90001; i++){
        if (vetor_dep_est[i].codigo) vetor_dep_est[cont_dep_est++] = vetor_dep_est[i];
    }
    qs_votos_M3(vetor_p, 0, cont_ps-1);
    qs_votos_M3(vetor_sen, 0, cont_sen-1);
    qs_votos_M3(vetor_dep_fed, 0, cont_dep_fed-1);
    qs_votos_M3(vetor_dep_est, 0, cont_dep_est-1);
    printf("%d %d\n", cont_val, cont_inval);
    if((float) vetor_p[cont_ps-1].n_votos >= cont_pres*0.51){
        printf("%d\n", vetor_p[cont_ps-1].codigo);
    } else {
        printf("Segundo turno\n");
    }          
    for(;n_sen > 1;n_sen--){
        printf("%d ", vetor_sen[cont_sen - 1].codigo); 
        cont_sen--;
    }
    printf("%d\n", vetor_sen[cont_sen - 1].codigo);        
    for(;n_dep_fed > 1;n_dep_fed--){
        printf("%d ", vetor_dep_fed[cont_dep_fed - 1].codigo); 
        cont_dep_fed--; 
    }
    printf("%d\n", vetor_dep_fed[cont_dep_fed - 1].codigo);
    for(;n_dep_est> 1;n_dep_est--){
        printf("%d ", vetor_dep_est[cont_dep_est-1].codigo);  
        cont_dep_est--;
    }
    printf("%d\n", vetor_dep_est[cont_dep_est-1].codigo);
}