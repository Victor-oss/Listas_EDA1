#include <stdio.h>

int main(){
    char time_a[101], time_b[101], n_final = 0, ptos_a = 0, ptos_b = 0, n_cobrancas, cont = 1;
    scanf("%hhd", &n_cobrancas);
    getchar();
    scanf("%s", time_a);
    getchar();
    scanf("%s", time_b); 
    while(*(time_a+cont-1) != '\0'){
        if(*(time_a+cont-1) == 'o'){
            ptos_a++;
        }

        if(((n_cobrancas - cont) < (ptos_b - ptos_a))){
            n_final = 2*cont - 1;
            break;
        }

        if(*(time_b+cont-1) == 'o'){
            ptos_b++;
        }

        if(((n_cobrancas - cont) < (ptos_b - ptos_a)) 
        || ((n_cobrancas - cont) < (ptos_a - ptos_b))){
            n_final = 2*cont;
            break;
        }
        cont++;
    }
    if(n_final == 0){
        printf("Empate\n");
    } else {
        printf("%hhd\n", n_final);
    }
}