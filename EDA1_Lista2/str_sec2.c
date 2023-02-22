#include <stdio.h>

int main(){
    int v[1000], i = 0;
    char *a;
    while(scanf("%x", &v[i++]) == 1);
    a = (char*) v;
    printf("%s\n", a);
}