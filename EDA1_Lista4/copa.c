#include <stdio.h>

int main(){
    char nome_time[11];
    int N, T, pontos_time, qtd_pontos, sair = 0;
    while(sair == 0){
        qtd_pontos= 0;
        scanf("%d %d", &T, &N);
        getchar();
        if(T == 0){
            sair = 1;
        } else {
            for(int i = 0; i < T; i++){
                scanf("%s %d", nome_time, &pontos_time);
                getchar();
                qtd_pontos += pontos_time;
            }
            printf("%d\n", 3*N - qtd_pontos);
        }
    }
}