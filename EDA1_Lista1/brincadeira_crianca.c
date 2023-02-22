#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, *seq, ganhos_Alice;
    scanf("%d", &N);
    while(N != 0){
        ganhos_Alice = 0;
        seq = (int*)malloc(N*sizeof(int));
        for(int i = 0; i < N-1; i++){
            scanf("%d ", &seq[i]);
        }
        scanf("%d", &seq[N-1]);
        for(int a = 0; a < N; a++){
            if(seq[a] == 0){
                ganhos_Alice++;
            }
        }
        printf("Alice ganhou %d e Beto ganhou %d\n", ganhos_Alice, N-ganhos_Alice);
        scanf("%d", &N);
    }
    return 0;
}