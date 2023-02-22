#include <stdio.h>

unsigned short int somdig(unsigned long long int  N){
    int resto = N%10;
    if(N < 10){
        return N;
    } 
    return somdig(N/10)+resto;
}

int main(){
    unsigned long long int N;
    scanf("%llu", &N);
    printf("%hu\n", somdig(N));
    return 0;
}