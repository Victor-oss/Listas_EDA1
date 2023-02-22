#include <stdio.h>

void lerValores(char* pont, int n_vezes){
    char indice = 0, pont_imp, pont_par;
    for(int i = 0; i < n_vezes; i++){
        scanf("%hhd %hhd", &pont_imp, &pont_par);
        getchar();
        if(pont_imp > pont_par){
            *(pont+i) = *(pont+indice);
        } else {
            *(pont+i) = *(pont+indice+1);
        }
        indice += 2;
    }
}

int main(){
    char times[16], indice = 0;
    for(int a = 65; a <= 80; a++) times[indice++] = a;
    lerValores(times, 8);
    lerValores(times, 4);
    lerValores(times, 2);
    lerValores(times, 1);
    printf("%c\n", times[0]);
}