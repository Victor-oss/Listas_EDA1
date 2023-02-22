#include <stdio.h> 
#include <stdlib.h>

int main(){
    int *cods, *notas, N, cont, maior, cod_do_maior;
    cont = 1;
    while(scanf("%d", &N) != EOF){
        cods = (int*)malloc(N*sizeof(int));
        notas = (int*)malloc(N*sizeof(int));
        for(int i = 0; i < N; i++){
            scanf(" %d %d", &cods[i], &notas[i]);
        }
        for(int a = 0; a < N; a++){
            for(int b = a+1; b < N; b++){
                if(notas[a] < notas[b]){
                    maior = notas[b];
                    cod_do_maior = cods[b];
                    notas[b] = notas[a];
                    cods[b] = cods[a];
                    notas[a] = maior;
                    cods[a] = cod_do_maior;
                }
            }
        }
        for(int a = 0; a < N; a++){
            for(int b = a+1; b < N; b++){
                if(notas[a] == notas[b] && cods[a] > cods[b]){
                    cod_do_maior = cods[b];
                    cods[b] = cods[a];
                    cods[a] = cod_do_maior;
                }
            }
        }
        printf("Dia %d\n", cont);
        printf("%d\n", cods[0]);
        printf("\n");
        cont++;
    }
    return 0;
}