#include <stdio.h>
#include <string.h>

int main(){
    char palavra[30];
    int achou = 0;
    while(scanf("%s", palavra) != EOF){
        if(strcmp(palavra, "marte")==0){
            achou = 1;
        }
    }
    if(achou == 1){
        printf("Leonardo Cicero Marciano");
    } else{
        printf("none");
    }
    return 0;
}