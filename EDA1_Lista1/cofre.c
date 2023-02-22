#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, *diferencas, dif, j, z, cont;
    scanf("%d", &N);
    cont = 1;
    while(N != 0){
        dif = 0;
        diferencas = (int*)malloc(N*sizeof(int));
        for(int i = 0; i<N; i++){
            scanf("%d %d", &j, &z);
            dif = dif + j - z;
            diferencas[i] = dif;
        }
        printf("Teste %d\n", cont);
        for(int i = 0; i<N; i++){
            printf("%d\n", diferencas[i]);
        }
        printf("\n");
        cont++;
        scanf("%d", &N);
    }
    return 0;
}