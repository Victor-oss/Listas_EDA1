#include <stdio.h>

int grau9(char* v9){
    int somadig = 0, i, sair = 0, cont = 0, resto, num_dig = 0, valor;
    char novo[5];
    while(*(v9+cont) != '\0') {
        valor = *(v9 + cont);
        somadig +=  valor - '0';
        cont++;
    }

    if(somadig == 0){
       return -1;
    }

    if(somadig%9 != 0){
        return 0;
    }

    if(somadig == 9){
        return 1;
    } else {
        i = somadig;
        if(somadig >= 1000){
            cont = 4;
        } else if(somadig >= 100){
            cont = 3;
        } else if(somadig >= 10){
            cont = 2;
        }
        novo[cont] = '\0';
        while(sair == 0){
            resto = i%10;
            i = i/10;
            if(i == 0){
                sair = 1;
            }
            novo[cont - 1] = resto+'0';
            cont--;
        }
        return grau9(novo) + 1;
    }
}

int main(){
    int n_grau, sair = 0;
    char vetor_noves[1001];
    while(sair == 0){
        scanf("%s", vetor_noves);
        n_grau = grau9(vetor_noves);
        if(n_grau == -1){
            sair = 1;
        } else if(n_grau == 0){
            printf("%s is not a multiple of 9.\n", vetor_noves);
        } else{
            printf("%s is a multiple of 9 and has 9-degree %d.\n", vetor_noves, n_grau);
        }
    }
    return 0;
}