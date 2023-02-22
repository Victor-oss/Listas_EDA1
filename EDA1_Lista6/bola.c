#include <stdio.h>

int main(){
    int N, A, L, P;
    scanf("%d", &N);
    scanf("%d %d %d", &A, &L, &P);
    if(A >= N && L >= N && P >= N){
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}