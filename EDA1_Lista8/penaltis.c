#include <stdio.h>

char ptos_a = 0, ptos_b = 0, n_cobrancas, cont = 1;

int qual_cobranca(char *vetor_a, char *vetor_b){
    if(*vetor_a == '\0') return 0;
    if(*vetor_a == 'o'){
        ptos_a++;
    }

    if(ptos_a > (ptos_b + n_cobrancas - cont + 1)){
      return (2*cont - 1);  
    }

    if((ptos_a + n_cobrancas - cont) < ptos_b){
      return (2*cont - 1);  
    }

    if(*vetor_b == 'o'){
        ptos_b++;
    }
    
    if(ptos_b > (ptos_a + n_cobrancas - cont)){
      return 2*cont;  
    }

    if((ptos_b + n_cobrancas - cont) < ptos_a){
      return 2*cont;  
    }

    cont++;
    return qual_cobranca(vetor_a+1, vetor_b+1);
}

int main(){
    char time_a[101], time_b[101];
    int n_final;
    scanf("%hhd", &n_cobrancas);
    getchar();
    scanf("%s", time_a);
    getchar();
    scanf("%s", time_b); 
    n_final = qual_cobranca(time_a, time_b);
    if(n_final == 0){
        printf("Empate\n");
    } else {
        printf("%d\n", n_final);
    }
}