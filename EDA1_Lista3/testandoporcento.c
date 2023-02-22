#include <stdio.h>

int main(){
    int x;
    char valores[100];
    //scanf("%x", &x);
    //printf("%d\n", x);

    //printf("%d\n", scanf("%*d %d %*d", &x));
    //printf("%d\n", x);

    printf("%d\n", scanf("%s%n", valores, &x));
    printf("%d\n", x);
}