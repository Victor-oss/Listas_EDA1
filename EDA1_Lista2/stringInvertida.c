#include <stdio.h>
void teste(char *s){
    if(*s == '\0') return;
    teste(s+1);
    printf("%c", *s);
}

int main(){
    char normal[4] = {'a', 'b', 'c', 'd'};
    teste(normal);
}
