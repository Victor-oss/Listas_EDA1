#include <stdio.h>
#include <stdlib.h>

unsigned long int f91(unsigned long int num){
    if(num >= 101){
        return num - 10;
    } else {
        return f91(f91(num+11));
    }
}

int main(){
    unsigned long int N;
    unsigned int sair = 0;
    while(sair == 0){
        scanf("%lu", &N);
        if(N == 0){
            sair = 1;
        } else {
            printf("f91(%lu) = %lu\n", N, f91(N));
        }
    }
    return 0;
}