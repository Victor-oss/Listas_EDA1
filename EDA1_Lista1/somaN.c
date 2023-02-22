#include <stdio.h>

int main(){
    int N, n_termo, res;
    scanf("%d", &N);
    res = 0;
    for(int i = 0; i<N-1; i++){
        scanf("%d\n", &n_termo);
        res = res + n_termo;
    }
    scanf("%d", &n_termo);
    res = res + n_termo;
    printf("%d", res);
    return 0;
}