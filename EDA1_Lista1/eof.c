#include <stdio.h>

int main(){
    int cont, n;
    cont = 0;
    while(scanf("%d", &n) != EOF){
        cont++;
    }
    printf("%d", cont);
    return 0;
}