#include <stdio.h>

int main(){
    short int c1,c2,c3;
    int palpite,total;
    scanf("%hd %hd %hd", &c1, &c2, &c3);
    total = c1+c2+c3;
    scanf("%d", &palpite);
    if(total == palpite){
        printf("Acertou\n");
    } else {
        printf("Errou\n");
    }
}