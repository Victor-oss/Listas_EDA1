#include <stdio.h>

int main(){
    unsigned int v[1000], i = 0;
    while(scanf("%x", &v[i++]) == 1);
    char *c = (char*) v;
    printf("%s", c);
}